# Adblock Detector for Defold

Finds adblock using [this](https://github.com/wmcmurray/just-detect-adblock) package and [this](https://incolumitas.com/2020/12/27/detecting-uBlock-Origin-and-Adblock-Plus-with-JavaScript-only/)

> &#x26a0;&#xfe0f; **neutral.js** and **pp34.js** files are added to the project to detect **AdGuard**, **uBlock Origin**, **Adblock Plus**.

> &#x26a0;&#xfe0f; Adblock blocks requests when it is enabled in the browser and **errors** may occur in the console.

> &#x26a0;&#xfe0f; When you run a **Build HTML** there may be bugs in the current Defold version.
> This is because the editor does not understand URL parameters.
> This does not affect to the **Bundle**.

## Installation

You can use it in your own project by adding this project as a [Defold library dependency](http://www.defold.com/manuals/libraries/). Open your `game.project` file and in the dependencies field add **a link to the ZIP file of a [specific release](https://github.com/potatojam/defold-adblock-detector/tags).**

## API

### `adblockdetector.detect(callback)`

Detect if a browser is using Adblock

**Parameters**

- `callback` <kbd>function</kbd> _required_ `function(self, result)`

## Example

```lua
local function on_complete(self, result)
    if result then
        print("Adblock detected")
    else
        print("Adblock not detected")
    end
end

function init(self)
    if adblockdetector then
        adblockdetector.detect(on_complete)
    end
end
```

## Credits

Made by [PotatoJam](https://github.com/potatojam).

Based on [just-detect-adblock](https://github.com/wmcmurray/just-detect-adblock)

And on [Detecting uBlock Origin and Adblock Plus with JavaScript only](https://incolumitas.com/2020/12/27/detecting-uBlock-Origin-and-Adblock-Plus-with-JavaScript-only/)

### License

MIT license
