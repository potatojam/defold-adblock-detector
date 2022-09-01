#define EXTENSION_NAME adblockdetector
#define LIB_NAME "AdblockDetector"
#define MODULE_NAME "adblockdetector"

// TODO: remove
// #define DM_PLATFORM_HTML5 true

#include <dmsdk/sdk.h>

#if defined(DM_PLATFORM_HTML5)

typedef void (*DetectCallback)(int success);

static dmScript::LuaCallbackInfo *adsDetect_Callback = 0x0;

extern "C"
{
    void AdsDetector_Detect(DetectCallback callback);
}

static void AdsDetector_InvokeCallback(int intArg, const char *charArg)
{
    if (!dmScript::IsCallbackValid(adsDetect_Callback))
    {
        dmLogError("AdblockDetector callback is invalid");
        return;
    }

    lua_State *L = dmScript::GetCallbackLuaContext(adsDetect_Callback);

    DM_LUA_STACK_CHECK(L, 0);

    if (!dmScript::SetupCallback(adsDetect_Callback))
    {
        return;
    }

    int numOfArgs = 0;

    lua_pushboolean(L, intArg);
    numOfArgs = 1;
    numOfArgs += 1;

    int ret = dmScript::PCall(L, numOfArgs, 0);
    (void)ret;

    dmScript::TeardownCallback(adsDetect_Callback);

    if (adsDetect_Callback != 0x0)
    {
        dmScript::DestroyCallback(adsDetect_Callback);
        adsDetect_Callback = 0x0;
    }
}

static void AdsDetector_DetectCallback(int success)
{
    AdsDetector_InvokeCallback(success, 0);
}

static int AdsDetector_StartDetect(lua_State *L)
{
    int type = lua_type(L, 1);
    if (type != LUA_TFUNCTION)
    {
        luaL_error(L, "AdblockDetector callback is invalid");
        return 0;
    }
    DM_LUA_STACK_CHECK(L, 0);
    adsDetect_Callback = dmScript::CreateCallback(L, 1);
    AdsDetector_Detect((DetectCallback)AdsDetector_DetectCallback);
    return 0;
}

// Functions exposed to Lua
static const luaL_reg Module_methods[] =
    {
        {"detect", AdsDetector_StartDetect},
        {0, 0}};

static void LuaInit(lua_State *L)
{
    int top = lua_gettop(L);

    luaL_register(L, MODULE_NAME, Module_methods);

    lua_pop(L, 1);
    assert(top == lua_gettop(L));
}

dmExtension::Result InitializeAdsDetector(dmExtension::Params *params)
{
    LuaInit(params->m_L);
    return dmExtension::RESULT_OK;
}

dmExtension::Result FinalizeAdsDetector(dmExtension::Params *params)
{
    return dmExtension::RESULT_OK;
}

#else // unsupported platforms

dmExtension::Result InitializeAdsDetector(dmExtension::Params *params)
{
    return dmExtension::RESULT_OK;
}

dmExtension::Result FinalizeAdsDetector(dmExtension::Params *params)
{
    return dmExtension::RESULT_OK;
}

#endif

DM_DECLARE_EXTENSION(EXTENSION_NAME, LIB_NAME, 0, 0, InitializeAdsDetector, 0, 0, FinalizeAdsDetector)
