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

    ../generated/Action.h
    ../generated/Action_wrappers.cpp
    ../Action.cpp
    ../ActionInternal.h

    ../generated/Application.h
    ../generated/Application_wrappers.cpp
    ../Application.cpp

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

    ../generated/DockWidget.h
    ../generated/DockWidget_wrappers.cpp
    ../DockWidget.cpp

    ../generated/Enums.h
    ../generated/Enums_wrappers.cpp
    ../Enums.cpp

    ../generated/FileDialog.h
    ../generated/FileDialog_wrappers.cpp
    ../FileDialog.cpp
    ../FileDialogInternal.h

    ../generated/Font.h
    ../generated/Font_wrappers.cpp
    ../Font.cpp
    ../FontInternal.h

    ../generated/Frame.h
    ../generated/Frame_wrappers.cpp
    ../Frame.cpp
    ../FrameInternal.h

    ../generated/GridLayout.h
    ../generated/GridLayout_wrappers.cpp
    ../GridLayout.cpp
    ../GridLayoutInternal.h

    ../generated/GroupBox.h
    ../generated/GroupBox_wrappers.cpp
    ../GroupBox.cpp
    ../GroupBoxInternal.h

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

    ../generated/LineEdit.h
    ../generated/LineEdit_wrappers.cpp
    ../LineEdit.cpp
    ../LineEditInternal.h

    ../generated/ListView.h
    ../generated/ListView_wrappers.cpp
    ../ListView.cpp
    ../ListViewInternal.h

    ../generated/MainWindow.h
    ../generated/MainWindow_wrappers.cpp
    ../MainWindow.cpp
    ../MainWindowInternal.h

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

    ../generated/PaintResources.h
    ../generated/PaintResources_wrappers.cpp
    ../PaintResourcesInternal.h                      # needed for internal struct definitions
    ../PaintResources.cpp

    ../generated/PersistentModelIndex.h
    ../generated/PersistentModelIndex_wrappers.cpp
    ../PersistentModelIndex.cpp

    ../generated/Pixmap.h
    ../generated/Pixmap_wrappers.cpp
    ../PixmapInternal.h
    ../Pixmap.cpp

    ../generated/PlainTextEdit.h
    ../generated/PlainTextEdit_wrappers.cpp
    ../PlainTextEdit.cpp
    ../PlainTextEditInternal.h

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

    ../generated/Region.h
    ../generated/Region_wrappers.cpp
    ../RegionInternal.h
    ../Region.cpp

    ../generated/RegularExpression.h
    ../generated/RegularExpression_wrappers.cpp
    ../RegularExpressionInternal.h
    ../RegularExpression.cpp

    ../generated/ScrollArea.h
    ../generated/ScrollArea_wrappers.cpp
    ../ScrollArea.cpp
    ../ScrollAreaInternal.h

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

    ../generated/StandardItem.h
    ../generated/StandardItem_wrappers.cpp
    ../StandardItem.cpp
    ../StandardItemInternal.h

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

    ../generated/TabBar.h
    ../generated/TabBar_wrappers.cpp
    ../TabBar.cpp
    ../TabBarInternal.h

    ../generated/TabWidget.h
    ../generated/TabWidget_wrappers.cpp
    ../TabWidget.cpp
    ../TabWidgetInternal.h

    ../generated/TextOption.h
    ../generated/TextOption_wrappers.cpp
    ../TextOption.cpp

    ../generated/Timer.h
    ../generated/Timer_wrappers.cpp
    ../Timer.cpp
    ../TimerInternal.h

    ../generated/ToolBar.h
    ../generated/ToolBar_wrappers.cpp
    ../ToolBar.cpp
    ../ToolBarInternal.h

    ../generated/TreeView.h
    ../generated/TreeView_wrappers.cpp
    ../TreeView.cpp
    ../TreeViewInternal.h

    ../generated/Variant.h
    ../generated/Variant_wrappers.cpp
    ../VariantInternal.h
    ../Variant.cpp

    ../generated/Widget.h
    ../generated/Widget_wrappers.cpp
    ../Widget.cpp
    ../WidgetInternal.h

    ../util/convert.h
    ../util/convert.cpp
    ../util/SignalStuff.h
)

target_link_libraries(MinimalQtImpl PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

target_compile_definitions(MinimalQtImpl PRIVATE QTTESTINGIMPL_LIBRARY)
