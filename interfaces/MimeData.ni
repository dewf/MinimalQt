module MimeData;

import Object;
import Variant;
import Url;

interface SignalHandler extends Object.SignalHandler;
// no extra signals

@nodispose
opaque ConstHandle extends Object.Handle {
    Variant.Owned colorData();
    Buffer<byte> data(string mimeType);
    Array<string> formats();
    bool hasColor();
    bool hasFormat(string mimeType);
    bool hasHtml();
    bool hasImage();
    bool hasText();
    bool hasUrls();
    string html();
    Variant.Owned imageData();
    string text();
    Url.OwnedList urls();
}

opaque Handle extends ConstHandle {
    void clear();
    void removeFormat(string mimeType);
    void setColorData(Variant.Handle color);
    void setData(string mimeType, Buffer<byte> data);
    void setHtml(string html);
    void setImageData(Variant.Handle image);
    void setText(string text);
    void setUrls(Url.List urls);
}

Handle create();
