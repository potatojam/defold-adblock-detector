# Adblock Detector for Defold

Finds adblock using [this](https://github.com/wmcmurray/just-detect-adblock) package.

> &#x26a0;&#xfe0f; Doesn't work for AdGuard and uBlock Origin

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

### License

MIT license
