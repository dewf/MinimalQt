#include "generated/MimeData.h"
#include "MimeDataInternal.h"

#include "UrlInternal.h"
#include "VariantInternal.h"

#include "util/convert.h"

using namespace ::Object;
using namespace ::Variant;
using namespace ::Url;

#define CONST_THIS (reinterpret_cast<const QMimeData*>(_this))
#define MUTABLE_THIS (reinterpret_cast<QMimeData*>(_this))

namespace MimeData
{
    // const methods ===============================

    Variant::OwnedRef ConstHandle_colorData(ConstHandleRef _this) {
        return VARIANT_HEAP_NEW(CONST_THIS->colorData());
    }

    std::shared_ptr<NativeBuffer<uint8_t>> ConstHandle_data(ConstHandleRef _this, const std::string& mimeType) {
        const auto qBytes = CONST_THIS->data(QString::fromStdString(mimeType));
        // allocate destination buffer
        std::vector bufferDims = { static_cast<int>(qBytes.size()) };
        const auto retBuffer = std::make_shared<ServerBuffer<uint8_t>>(bufferDims);
        // perform the copy
        std::memcpy(retBuffer->getSpan(nullptr), qBytes.data(), qBytes.size());
        // bye
        return retBuffer;
    }

    std::vector<std::string> ConstHandle_formats(ConstHandleRef _this) {
        return toVectorStrings(CONST_THIS->formats());
    }

    bool ConstHandle_hasColor(ConstHandleRef _this) {
        return CONST_THIS->hasColor();
    }

    bool ConstHandle_hasFormat(ConstHandleRef _this, const std::string& mimeType) {
        return CONST_THIS->hasFormat(QString::fromStdString(mimeType));
    }

    bool ConstHandle_hasHtml(ConstHandleRef _this) {
        return CONST_THIS->hasHtml();
    }

    bool ConstHandle_hasImage(ConstHandleRef _this) {
        return CONST_THIS->hasImage();
    }

    bool ConstHandle_hasText(ConstHandleRef _this) {
        return CONST_THIS->hasText();
    }

    bool ConstHandle_hasUrls(ConstHandleRef _this) {
        return CONST_THIS->hasUrls();
    }

    std::string ConstHandle_html(ConstHandleRef _this) {
        return CONST_THIS->html().toStdString();
    }

    Variant::OwnedRef ConstHandle_imageData(ConstHandleRef _this) {
        return VARIANT_HEAP_NEW(CONST_THIS->imageData());
    }

    std::string ConstHandle_text(ConstHandleRef _this) {
        return CONST_THIS->text().toStdString();
    }

    ListRef ConstHandle_urls(ConstHandleRef _this) {
        return new __List { CONST_THIS->urls() };
    }

    // non-const methods ==========================================================================================

    void Handle_clear(HandleRef _this) {
        MUTABLE_THIS->clear();
    }

    void Handle_removeFormat(HandleRef _this, const std::string& mimeType) {
        MUTABLE_THIS->removeFormat(QString::fromStdString(mimeType));
    }

    void Handle_setColorData(HandleRef _this, Variant::HandleRef color) {
        MUTABLE_THIS->setColorData(QVARIANT_VALUE(color));
    }

    void Handle_setData(HandleRef _this, const std::string& mimeType, const std::shared_ptr<NativeBuffer<uint8_t>>& data) {
        size_t length;
        const auto dataPtr = reinterpret_cast<const char *>(data->getSpan(&length));
        const QByteArray qBytes(dataPtr, static_cast<qsizetype>(length));
        MUTABLE_THIS->setData(QString::fromStdString(mimeType), qBytes);
    }

    void Handle_setHtml(HandleRef _this, const std::string& html) {
        MUTABLE_THIS->setHtml(QString::fromStdString(html));
    }

    void Handle_setImageData(HandleRef _this, Variant::HandleRef image) {
        MUTABLE_THIS->setImageData(QVARIANT_VALUE(image));
    }

    void Handle_setText(HandleRef _this, const std::string& text) {
        return MUTABLE_THIS->setText(QString::fromStdString(text));
    }

    void Handle_setUrls(HandleRef _this, ListRef urls) {
        MUTABLE_THIS->setUrls(urls->qList);
    }

    void Handle_dispose(HandleRef _this) {
        delete MUTABLE_THIS;
    }

    HandleRef create() {
        return reinterpret_cast<HandleRef>(new QMimeData());
    }
}
