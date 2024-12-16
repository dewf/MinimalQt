#include "generated/GridLayout.h"

#include <QGridLayout>
#include <utility>

#include "util/SignalStuff.h"
#include "util/convert.h"

#define THIS ((GridLayoutWithHandler*)_this)

#include "signalrelays/GridLayout.h"

namespace GridLayout {
    class GridLayoutWithHandler : public QGridLayout {
        Q_OBJECT
    private:
        SignalRelay relay;
    public:
        explicit GridLayoutWithHandler(const std::shared_ptr<SignalHandler>& handler) : relay(this, handler) {}
        void setSignalMask(SignalMask newMask) {
            relay.setSignalMask(newMask);
        }
    };

    void Handle_setHorizontalSpacing(HandleRef _this, int32_t value) {
        THIS->setHorizontalSpacing(value);
    }

    void Handle_setVerticalSpacing(HandleRef _this, int32_t value) {
        THIS->setVerticalSpacing(value);
    }

    void Handle_addWidget(HandleRef _this, Widget::HandleRef widget, int32_t row, int32_t col) {
        THIS->addWidget(reinterpret_cast<QWidget *>(widget), row, col);
    }

    void Handle_addWidget(HandleRef _this, Widget::HandleRef widget, int32_t row, int32_t col, Alignment align) {
        THIS->addWidget(reinterpret_cast<QWidget *>(widget), row, col, (Qt::AlignmentFlag) align);
    }

    void Handle_addWidget(HandleRef _this, Widget::HandleRef widget, int32_t row, int32_t col, int32_t rowSpan, int32_t colSpan) {
        THIS->addWidget(reinterpret_cast<QWidget *>(widget), row, col, rowSpan, colSpan);
    }

    void Handle_addWidget(HandleRef _this, Widget::HandleRef widget, int32_t row, int32_t col, int32_t rowSpan, int32_t colSpan, Enums::Alignment align) {
        THIS->addWidget(reinterpret_cast<QWidget *>(widget), row, col, rowSpan, colSpan, (Qt::AlignmentFlag) align);
    }

    void Handle_addLayout(HandleRef _this, Layout::HandleRef layout, int32_t row, int32_t col) {
        THIS->addLayout(reinterpret_cast<QLayout *>(layout), row, col);
    }

    void Handle_addLayout(HandleRef _this, Layout::HandleRef layout, int32_t row, int32_t col, Enums::Alignment align) {
        THIS->addLayout(reinterpret_cast<QLayout *>(layout), row, col, (Qt::AlignmentFlag) align);
    }

    void Handle_addLayout(HandleRef _this, Layout::HandleRef layout, int32_t row, int32_t col, int32_t rowSpan, int32_t colSpan) {
        THIS->addLayout(reinterpret_cast<QLayout *>(layout), row, col, rowSpan, colSpan);
    }

    void Handle_addLayout(HandleRef _this, Layout::HandleRef layout, int32_t row, int32_t col, int32_t rowSpan, int32_t colSpan, Enums::Alignment align) {
        THIS->addLayout(reinterpret_cast<QLayout *>(layout), row, col, rowSpan, colSpan, (Qt::AlignmentFlag) align);
    }

    void Handle_setRowMinimumHeight(HandleRef _this, int32_t row, int32_t minHeight) {
        THIS->setRowMinimumHeight(row, minHeight);
    }

    void Handle_setRowStretch(HandleRef _this, int32_t row, int32_t stretch) {
        THIS->setRowStretch(row, stretch);
    }

    void Handle_setColumnMinimumWidth(HandleRef _this, int32_t column, int32_t minWidth) {
        THIS->setColumnMinimumWidth(column, minWidth);
    }

    void Handle_setColumnStretch(HandleRef _this, int32_t column, int32_t stretch) {
        THIS->setColumnStretch(column, stretch);
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new GridLayoutWithHandler(handler));
    }
}

#include "GridLayout.moc"
