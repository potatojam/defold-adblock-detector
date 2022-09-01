var LibAdsDetector = {

    $AdblockDetector: {

        _callback: null,

        _detectCallback: function (success) {
            var msg = success ? 1 : 0;
            {{{ makeDynCall("vi", "AdblockDetector._callback")}}}(msg);
        },
    },

    AdsDetector_Detect: function (callback) {
        AdblockDetector._callback = callback;
        justDetectAdblock.detectAnyAdblocker().then(function (detected) {
            AdblockDetector._detectCallback(detected);
        });
    },
}

autoAddDeps(LibAdsDetector, '$AdblockDetector');
mergeInto(LibraryManager.library, LibAdsDetector);
