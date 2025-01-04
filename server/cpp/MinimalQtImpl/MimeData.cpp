#include "generated/MimeData.h"

#include <QUrl>

#include "MimeDataInternal.h"
#include "UrlInternal.h"
#include "VariantInternal.h"

#include "util/convert.h"

// #define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
// #define MIMEDATA_THIS (WRAPPER->getActual())
#define THIS (reinterpret_cast<QMimeData*>(_this))

namespace MimeData
{
    void Handle_clear(HandleRef _this) {
        THIS->clear();
    }

    Variant::OwnedRef Handle_colorData(HandleRef _this) {
        return new Variant::__Owned { THIS->colorData() };
    }

    std::shared_ptr<NativeBuffer<uint8_t>> Handle_data(HandleRef _this, const std::string& mimeType) {
        const auto qBytes = THIS->data(QString::fromStdString(mimeType));
        // allocate destination buffer
        std::vector bufferDims = { static_cast<int>(qBytes.size()) };
        const auto retBuffer = std::make_shared<ServerBuffer<uint8_t>>(bufferDims);
        // perform the copy
        std::memcpy(retBuffer->getSpan(nullptr), qBytes.data(), qBytes.size());
        // bye
        return retBuffer;
    }

    std::vector<std::string> Handle_formats(HandleRef _this) {
        return toVectorStrings(THIS->formats());
    }

    bool Handle_hasColor(HandleRef _this) {
        return THIS->hasColor();
    }

    bool Handle_hasFormat(HandleRef _this, const std::string& mimeType) {
        return THIS->hasFormat(QString::fromStdString(mimeType));
    }

    bool Handle_hasHtml(HandleRef _this) {
        return THIS->hasHtml();
    }

    bool Handle_hasImage(HandleRef _this) {
        return THIS->hasImage();
    }

    bool Handle_hasText(HandleRef _this) {
        return THIS->hasText();
    }

    bool Handle_hasUrls(HandleRef _this) {
        return THIS->hasUrls();
    }

    std::string Handle_html(HandleRef _this) {
        return THIS->html().toStdString();
    }

    Variant::OwnedRef Handle_imageData(HandleRef _this) {
        return new Variant::__Owned { THIS->imageData() };
    }

    void Handle_removeFormat(HandleRef _this, const std::string& mimeType) {
        THIS->removeFormat(QString::fromStdString(mimeType));
    }

    void Handle_setColorData(HandleRef _this, Variant::HandleRef color) {
        THIS->setColorData(color->value);
    }

    void Handle_setData(HandleRef _this, const std::string& mimeType, const std::shared_ptr<NativeBuffer<uint8_t>>& data) {
        size_t length;
        const auto dataPtr = reinterpret_cast<const char *>(data->getSpan(&length));
        const QByteArray qBytes(dataPtr, static_cast<qsizetype>(length));
        THIS->setData(QString::fromStdString(mimeType), qBytes);
    }

    void Handle_setHtml(HandleRef _this, const std::string& html) {
        THIS->setHtml(QString::fromStdString(html));
    }

    void Handle_setImageData(HandleRef _this, Variant::HandleRef image) {
        THIS->setImageData(image->value);
    }

    void Handle_setText(HandleRef _this, const std::string& text) {
        return THIS->setText(QString::fromStdString(text));
    }

    void Handle_setUrls(HandleRef _this, const std::vector<Url::HandleRef>& urls) {
        const auto urlList = toQList<Url::HandleRef,QUrl>(urls, [](auto url) { return QURL_VALUE(url); });
        THIS->setUrls(urlList);
    }

    std::string Handle_text(HandleRef _this) {
        return THIS->text().toStdString();
    }

    std::vector<Url::OwnedRef> Handle_urls(HandleRef _this) {
        return fromQList<QUrl,Url::OwnedRef>(THIS->urls(), [](auto url) { return URL_HEAP_NEW(url); });
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create() {
        return reinterpret_cast<HandleRef>(new QMimeData());
    }
}
