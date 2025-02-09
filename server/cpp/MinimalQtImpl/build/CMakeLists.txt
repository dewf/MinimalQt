cmake_minimum_required(VERSION 3.14)

project(MinimalQtImpl LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_library(MinimalQtImpl STATIC
    ../support/NativeImplServer.cpp
    ../generated/Library.cpp

    ../generated/AbstractButton.h
    ../generated/AbstractButton_wrappers.cpp
    ../AbstractButton.cpp
    ../AbstractButtonInternal.h

    ../generated/AbstractItemDelegate.h
    ../generated/AbstractItemDelegate_wrappers.cpp
    ../AbstractItemDelegate.cpp
    ../AbstractItemDelegateInternal.h

    ../generated/AbstractItemModel.h
    ../generated/AbstractItemModel_wrappers.cpp
    ../AbstractItemModel.cpp
    ../AbstractItemModelInternal.h

    ../generated/AbstractItemView.h
    ../generated/AbstractItemView_wrappers.cpp
    ../AbstractItemView.cpp
    ../AbstractItemViewInternal.h

    ../generated/AbstractListModel.h
    ../generated/AbstractListModel_wrappers.cpp
    ../AbstractListModel.cpp
    ../AbstractListModelInternal.h

    ../generated/AbstractProxyModel.h
    ../generated/AbstractProxyModel_wrappers.cpp
    ../AbstractProxyModel.cpp
    ../AbstractProxyModelInternal.h

    ../generated/AbstractScrollArea.h
    ../generated/AbstractScrollArea_wrappers.cpp
    ../AbstractScrollArea.cpp
    ../AbstractScrollAreaInternal.h

    ../generated/AbstractSlider.h
    ../generated/AbstractSlider_wrappers.cpp
    ../AbstractSlider.cpp
    ../AbstractSliderInternal.h

    ../generated/AbstractSpinBox.h
    ../generated/AbstractSpinBox_wrappers.cpp
    ../AbstractSpinBox.cpp
    ../AbstractSpinBoxInternal.h

    ../generated/Action.h
    ../generated/Action_wrappers.cpp
    ../Action.cpp
    ../ActionInternal.h

    ../generated/Application.h
    ../generated/Application_wrappers.cpp
    ../Application.cpp
    ../ApplicationInternal.h

    ../generated/BoxLayout.h
    ../generated/BoxLayout_wrappers.cpp
    ../BoxLayout.cpp
    ../BoxLayoutInternal.h

    ../generated/Brush.h
    ../generated/Brush_wrappers.cpp
    ../Brush.cpp
    ../BrushInternal.h

    ../generated/CalendarWidget.h
    ../generated/CalendarWidget_wrappers.cpp
    ../CalendarWidget.cpp
    ../CalendarWidgetInternal.h

    ../generated/CheckBox.h
    ../generated/CheckBox_wrappers.cpp
    ../CheckBox.cpp
    ../CheckBoxInternal.h

    ../generated/Color.h
    ../generated/Color_wrappers.cpp
    ../Color.cpp
    ../ColorInternal.h

    ../generated/ComboBox.h
    ../generated/ComboBox_wrappers.cpp
    ../ComboBox.cpp
    ../ComboBoxInternal.h

    ../generated/Common.h
    ../generated/Common_wrappers.cpp
    ../Common.cpp
    ../CommonInternal.h

    ../generated/Completer.h
    ../generated/Completer_wrappers.cpp
    ../Completer.cpp
    ../CompleterInternal.h

    ../generated/CoreApplication.h
    ../generated/CoreApplication_wrappers.cpp
    ../CoreApplication.cpp
    ../CoreApplicationInternal.h

    ../generated/Cursor.h
    ../generated/Cursor_wrappers.cpp
    ../CursorInternal.h
    ../Cursor.cpp

    ../generated/Date.h
    ../generated/Date_wrappers.cpp
    ../DateInternal.h
    ../Date.cpp

    ../generated/DateTime.h
    ../generated/DateTime_wrappers.cpp
    ../DateTimeInternal.h
    ../DateTime.cpp

    ../generated/Dialog.h
    ../generated/Dialog_wrappers.cpp
    ../Dialog.cpp
    ../DialogInternal.h

    ../generated/Dir.h
    ../generated/Dir_wrappers.cpp
    ../Dir.cpp
    ../DirInternal.h

    ../generated/DockWidget.h
    ../generated/DockWidget_wrappers.cpp
    ../DockWidget.cpp
    ../DockWidgetInternal.h

    ../generated/Drag.h
    ../generated/Drag_wrappers.cpp
    ../Drag.cpp
    ../DragInternal.h

    ../generated/Enums.h
    ../generated/Enums_wrappers.cpp
    ../Enums.cpp

    ../generated/Event.h
    ../generated/Event_wrappers.cpp
    ../Event.cpp
    ../EventInternal.h

    ../generated/FileDialog.h
    ../generated/FileDialog_wrappers.cpp
    ../FileDialog.cpp
    ../FileDialogInternal.h

    ../generated/Font.h
    ../generated/Font_wrappers.cpp
    ../Font.cpp
    ../FontInternal.h

    ../generated/FormLayout.h
    ../generated/FormLayout_wrappers.cpp
    ../FormLayout.cpp
    ../FormLayoutInternal.h

    ../generated/Frame.h
    ../generated/Frame_wrappers.cpp
    ../Frame.cpp
    ../FrameInternal.h

    ../generated/Gradient.h
    ../generated/Gradient_wrappers.cpp
    ../Gradient.cpp
    ../GradientInternal.h

    ../generated/GraphicsEffect.h
    ../generated/GraphicsEffect_wrappers.cpp
    ../GraphicsEffect.cpp
    ../GraphicsEffectInternal.h

    ../generated/GridLayout.h
    ../generated/GridLayout_wrappers.cpp
    ../GridLayout.cpp
    ../GridLayoutInternal.h

    ../generated/GroupBox.h
    ../generated/GroupBox_wrappers.cpp
    ../GroupBox.cpp
    ../GroupBoxInternal.h

    ../generated/GuiApplication.h
    ../generated/GuiApplication_wrappers.cpp
    ../GuiApplication.cpp
    ../GuiApplicationInternal.h

    ../generated/HeaderView.h
    ../generated/HeaderView_wrappers.cpp
    ../HeaderView.cpp
    ../HeaderViewInternal.h

    ../generated/Icon.h
    ../generated/Icon_wrappers.cpp
    ../Icon.cpp
    ../IconInternal.h                           # needed for internal struct definitions (when accessing icons from other modules)

    ../generated/Image.h
    ../generated/Image_wrappers.cpp
    ../Image.cpp
    ../ImageInternal.h                          # for deferred etc

    ../generated/ItemSelection.h
    ../generated/ItemSelection_wrappers.cpp
    ../ItemSelection.cpp
    ../ItemSelectionInternal.h

    ../generated/ItemSelectionCommon.h
    ../generated/ItemSelectionCommon_wrappers.cpp
    ../ItemSelectionCommon.cpp

    ../generated/ItemSelectionModel.h
    ../generated/ItemSelectionModel_wrappers.cpp
    ../ItemSelectionModel.cpp
    ../ItemSelectionModelInternal.h

    ../generated/KeySequence.h
    ../generated/KeySequence_wrappers.cpp
    ../KeySequenceInternal.h
    ../KeySequence.cpp

    ../generated/Label.h
    ../generated/Label_wrappers.cpp
    ../Label.cpp
    ../LabelInternal.h

    ../generated/Layout.h
    ../generated/Layout_wrappers.cpp
    ../Layout.cpp
    ../LayoutInternal.h

    ../generated/LayoutItem.h
    ../generated/LayoutItem_wrappers.cpp
    ../LayoutItem.cpp
    ../LayoutItemInternal.h

    ../generated/LineEdit.h
    ../generated/LineEdit_wrappers.cpp
    ../LineEdit.cpp
    ../LineEditInternal.h

    ../generated/ListView.h
    ../generated/ListView_wrappers.cpp
    ../ListView.cpp
    ../ListViewInternal.h

    ../generated/Logging.h
    ../generated/Logging_wrappers.cpp
    ../Logging.cpp
    ../LoggingInternal.h

    ../generated/MainWindow.h
    ../generated/MainWindow_wrappers.cpp
    ../MainWindow.cpp
    ../MainWindowInternal.h

    ../generated/Margins.h
    ../generated/Margins_wrappers.cpp
    ../Margins.cpp
    ../MarginsInternal.h

    ../generated/Menu.h
    ../generated/Menu_wrappers.cpp
    ../Menu.cpp
    ../MenuInternal.h

    ../generated/MenuBar.h
    ../generated/MenuBar_wrappers.cpp
    ../MenuBar.cpp
    ../MenuBarInternal.h

    ../generated/MessageBox.h
    ../generated/MessageBox_wrappers.cpp
    ../MessageBox.cpp
    ../MessageBoxInternal.h

    ../generated/MimeData.h
    ../generated/MimeData_wrappers.cpp
    ../MimeData.cpp
    ../MimeDataInternal.h

    ../generated/ModelIndex.h
    ../generated/ModelIndex_wrappers.cpp
    ../ModelIndexInternal.h
    ../ModelIndex.cpp

    ../generated/Object.h
    ../generated/Object_wrappers.cpp
    ../Object.cpp
    ../ObjectInternal.h

    ../generated/PaintDevice.h
    ../generated/PaintDevice_wrappers.cpp
    ../PaintDevice.cpp
    ../PaintDeviceInternal.h

    ../generated/Painter.h
    ../generated/Painter_wrappers.cpp
    ../Painter.cpp
    ../PainterInternal.h

    ../generated/PainterPath.h
    ../generated/PainterPath_wrappers.cpp
    ../PainterPath.cpp
    ../PainterPathInternal.h

    ../generated/Pen.h
    ../generated/Pen_wrappers.cpp
    ../Pen.cpp
    ../PenInternal.h

    ../generated/PersistentModelIndex.h
    ../generated/PersistentModelIndex_wrappers.cpp
    ../PersistentModelIndex.cpp
    ../PersistentModelIndexInternal.h

    ../generated/Pixmap.h
    ../generated/Pixmap_wrappers.cpp
    ../PixmapInternal.h
    ../Pixmap.cpp

    ../generated/PlainTextEdit.h
    ../generated/PlainTextEdit_wrappers.cpp
    ../PlainTextEdit.cpp
    ../PlainTextEditInternal.h

    ../generated/Point.h
    ../generated/Point_wrappers.cpp
    ../Point.cpp
    ../PointInternal.h

    ../generated/PointF.h
    ../generated/PointF_wrappers.cpp
    ../PointF.cpp
    ../PointFInternal.h

    ../generated/Polygon.h
    ../generated/Polygon_wrappers.cpp
    ../Polygon.cpp
    ../PolygonInternal.h

    ../generated/PolygonF.h
    ../generated/PolygonF_wrappers.cpp
    ../PolygonF.cpp
    ../PolygonFInternal.h

    ../generated/ProgressBar.h
    ../generated/ProgressBar_wrappers.cpp
    ../ProgressBar.cpp
    ../ProgressBarInternal.h

    ../generated/PushButton.h
    ../generated/PushButton_wrappers.cpp
    ../PushButton.cpp
    ../PushButtonInternal.h

    ../generated/RadioButton.h
    ../generated/RadioButton_wrappers.cpp
    ../RadioButton.cpp
    ../RadioButtonInternal.h

    ../generated/Rect.h
    ../generated/Rect_wrappers.cpp
    ../Rect.cpp
    ../RectInternal.h

    ../generated/RectF.h
    ../generated/RectF_wrappers.cpp
    ../RectF.cpp
    ../RectFInternal.h

    ../generated/Region.h
    ../generated/Region_wrappers.cpp
    ../Region.cpp
    ../RegionInternal.h

    ../generated/RegularExpression.h
    ../generated/RegularExpression_wrappers.cpp
    ../RegularExpression.cpp
    ../RegularExpressionInternal.h

    ../generated/RegularExpressionValidator.h
    ../generated/RegularExpressionValidator_wrappers.cpp
    ../RegularExpressionValidatorInternal.h
    ../RegularExpressionValidator.cpp

    ../generated/SafeReturn.h
    ../generated/SafeReturn_wrappers.cpp
    ../SafeReturn.cpp
    ../SafeReturnInternal.h

    ../generated/Screen.h
    ../generated/Screen_wrappers.cpp
    ../Screen.cpp
    ../ScreenInternal.h

    ../generated/ScrollArea.h
    ../generated/ScrollArea_wrappers.cpp
    ../ScrollArea.cpp
    ../ScrollAreaInternal.h

    ../generated/ScrollBar.h
    ../generated/ScrollBar_wrappers.cpp
    ../ScrollBar.cpp
    ../ScrollBarInternal.h

    ../generated/SessionManager.h
    ../generated/SessionManager_wrappers.cpp
    ../SessionManager.cpp
    ../SessionManagerInternal.h

    ../generated/Size.h
    ../generated/Size_wrappers.cpp
    ../SizeInternal.h
    ../Size.cpp

    ../generated/SizeF.h
    ../generated/SizeF_wrappers.cpp
    ../SizeFInternal.h
    ../SizeF.cpp

    ../generated/SizePolicy.h
    ../generated/SizePolicy_wrappers.cpp
    ../SizePolicyInternal.h
    ../SizePolicy.cpp

    ../generated/Slider.h
    ../generated/Slider_wrappers.cpp
    ../Slider.cpp
    ../SliderInternal.h

    ../generated/SortFilterProxyModel.h
    ../generated/SortFilterProxyModel_wrappers.cpp
    ../SortFilterProxyModel.cpp
    ../SortFilterProxyModelInternal.h

    ../generated/SpinBox.h
    ../generated/SpinBox_wrappers.cpp
    ../SpinBox.cpp
    ../SpinBoxInternal.h

    ../generated/Splitter.h
    ../generated/Splitter_wrappers.cpp
    ../Splitter.cpp
    ../SplitterInternal.h

    ../generated/SplitterHandle.h
    ../generated/SplitterHandle_wrappers.cpp
    ../SplitterHandle.cpp
    ../SplitterHandleInternal.h

    ../generated/StandardItem.h
    ../generated/StandardItem_wrappers.cpp
    ../StandardItem.cpp
    ../StandardItemInternal.h

    ../generated/StandardItemModel.h
    ../generated/StandardItemModel_wrappers.cpp
    ../StandardItemModel.cpp
    ../StandardItemModelInternal.h

    ../generated/StatusBar.h
    ../generated/StatusBar_wrappers.cpp
    ../StatusBar.cpp
    ../StatusBarInternal.h

    ../generated/StyledItemDelegate.h
    ../generated/StyledItemDelegate_wrappers.cpp
    ../StyledItemDelegate.cpp
    ../StyledItemDelegateInternal.h

    ../generated/StyleOption.h
    ../generated/StyleOption_wrappers.cpp
    ../StyleOption.cpp

    ../generated/StyleOptionViewItem.h
    ../generated/StyleOptionViewItem_wrappers.cpp
    ../StyleOptionViewItem.cpp
    ../StyleOptionViewItemInternal.h

    ../generated/TabBar.h
    ../generated/TabBar_wrappers.cpp
    ../TabBar.cpp
    ../TabBarInternal.h

    ../generated/TabWidget.h
    ../generated/TabWidget_wrappers.cpp
    ../TabWidget.cpp
    ../TabWidgetInternal.h

    ../generated/TextCharFormat.h
    ../generated/TextCharFormat_wrappers.cpp
    ../TextCharFormat.cpp
    ../TextCharFormatInternal.h

    ../generated/TextCursor.h
    ../generated/TextCursor_wrappers.cpp
    ../TextCursor.cpp
    ../TextCursorInternal.h

    ../generated/TextDocument.h
    ../generated/TextDocument_wrappers.cpp
    ../TextDocument.cpp
    ../TextDocumentInternal.h

    ../generated/TextEdit.h
    ../generated/TextEdit_wrappers.cpp
    ../TextEdit.cpp
    ../TextEditInternal.h

    ../generated/TextFormat.h
    ../generated/TextFormat_wrappers.cpp
    ../TextFormat.cpp
    ../TextFormatInternal.h

    ../generated/TextOption.h
    ../generated/TextOption_wrappers.cpp
    ../TextOption.cpp
    ../TextOptionInternal.h

    ../generated/Timer.h
    ../generated/Timer_wrappers.cpp
    ../Timer.cpp
    ../TimerInternal.h

    ../generated/ToolBar.h
    ../generated/ToolBar_wrappers.cpp
    ../ToolBar.cpp
    ../ToolBarInternal.h

    ../generated/Transform.h
    ../generated/Transform_wrappers.cpp
    ../Transform.cpp
    ../TransformInternal.h

    ../generated/TreeView.h
    ../generated/TreeView_wrappers.cpp
    ../TreeView.cpp
    ../TreeViewInternal.h

    ../generated/Url.h
    ../generated/Url_wrappers.cpp
    ../Url.cpp
    ../UrlInternal.h

    ../generated/Validator.h
    ../generated/Validator_wrappers.cpp
    ../Validator.cpp
    ../ValidatorInternal.h

    ../generated/Variant.h
    ../generated/Variant_wrappers.cpp
    ../Variant.cpp
    ../VariantInternal.h

    ../generated/Widget.h
    ../generated/Widget_wrappers.cpp
    ../Widget.cpp
    ../WidgetInternal.h

    ../generated/Window.h
    ../generated/Window_wrappers.cpp
    ../Window.cpp
    ../WindowInternal.h

    ../util/convert.h
    ../util/convert.cpp
    ../util/SignalStuff.h
)

target_link_libraries(MinimalQtImpl PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

target_compile_definitions(MinimalQtImpl PRIVATE QTTESTINGIMPL_LIBRARY)
