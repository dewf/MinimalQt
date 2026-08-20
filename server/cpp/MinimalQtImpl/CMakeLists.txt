# generated file - any edits will be overwritten!
cmake_minimum_required(VERSION 4.2)
project(MinimalQtImpl LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN YES)

#find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_library(MinimalQtImpl STATIC)

target_sources(MinimalQtImpl
        PRIVATE
        # support
        source/support/CoreStuff.h
        source/support/NativeImplServer.h
        source/support/NativeImplServer.cpp
        source/support/result.h

        # util
        source/util/convert.h
        source/util/convert.cpp
        source/util/SignalStuff.h

        # module Window
        source/generated/Window.h
        source/generated/Window_wrappers.h
        source/generated/Window_wrappers.cpp
        source/Window.cpp
        # module Widget
        source/generated/Widget.h
        source/generated/Widget_wrappers.h
        source/generated/Widget_wrappers.cpp
        source/Widget.cpp
        # module Variant
        source/generated/Variant.h
        source/generated/Variant_wrappers.h
        source/generated/Variant_wrappers.cpp
        source/Variant.cpp
        # module Validator
        source/generated/Validator.h
        source/generated/Validator_wrappers.h
        source/generated/Validator_wrappers.cpp
        source/Validator.cpp
        # module Url
        source/generated/Url.h
        source/generated/Url_wrappers.h
        source/generated/Url_wrappers.cpp
        source/Url.cpp
        # module TreeView
        source/generated/TreeView.h
        source/generated/TreeView_wrappers.h
        source/generated/TreeView_wrappers.cpp
        source/TreeView.cpp
        # module Transform
        source/generated/Transform.h
        source/generated/Transform_wrappers.h
        source/generated/Transform_wrappers.cpp
        source/Transform.cpp
        # module ToolBar
        source/generated/ToolBar.h
        source/generated/ToolBar_wrappers.h
        source/generated/ToolBar_wrappers.cpp
        source/ToolBar.cpp
        # module Timer
        source/generated/Timer.h
        source/generated/Timer_wrappers.h
        source/generated/Timer_wrappers.cpp
        source/Timer.cpp
        # module TextOption
        source/generated/TextOption.h
        source/generated/TextOption_wrappers.h
        source/generated/TextOption_wrappers.cpp
        source/TextOption.cpp
        # module TextFormat
        source/generated/TextFormat.h
        source/generated/TextFormat_wrappers.h
        source/generated/TextFormat_wrappers.cpp
        source/TextFormat.cpp
        # module TextEdit
        source/generated/TextEdit.h
        source/generated/TextEdit_wrappers.h
        source/generated/TextEdit_wrappers.cpp
        source/TextEdit.cpp
        # module TextDocument
        source/generated/TextDocument.h
        source/generated/TextDocument_wrappers.h
        source/generated/TextDocument_wrappers.cpp
        source/TextDocument.cpp
        # module TextCursor
        source/generated/TextCursor.h
        source/generated/TextCursor_wrappers.h
        source/generated/TextCursor_wrappers.cpp
        source/TextCursor.cpp
        # module TextCharFormat
        source/generated/TextCharFormat.h
        source/generated/TextCharFormat_wrappers.h
        source/generated/TextCharFormat_wrappers.cpp
        source/TextCharFormat.cpp
        # module TabWidget
        source/generated/TabWidget.h
        source/generated/TabWidget_wrappers.h
        source/generated/TabWidget_wrappers.cpp
        source/TabWidget.cpp
        # module TabBar
        source/generated/TabBar.h
        source/generated/TabBar_wrappers.h
        source/generated/TabBar_wrappers.cpp
        source/TabBar.cpp
        # module StyledItemDelegate
        source/generated/StyledItemDelegate.h
        source/generated/StyledItemDelegate_wrappers.h
        source/generated/StyledItemDelegate_wrappers.cpp
        source/StyledItemDelegate.cpp
        # module StyleOptionViewItem
        source/generated/StyleOptionViewItem.h
        source/generated/StyleOptionViewItem_wrappers.h
        source/generated/StyleOptionViewItem_wrappers.cpp
        source/StyleOptionViewItem.cpp
        # module StyleOption
        source/generated/StyleOption.h
        source/generated/StyleOption_wrappers.h
        source/generated/StyleOption_wrappers.cpp
        source/StyleOption.cpp
        # module StatusBar
        source/generated/StatusBar.h
        source/generated/StatusBar_wrappers.h
        source/generated/StatusBar_wrappers.cpp
        source/StatusBar.cpp
        # module StandardItemModel
        source/generated/StandardItemModel.h
        source/generated/StandardItemModel_wrappers.h
        source/generated/StandardItemModel_wrappers.cpp
        source/StandardItemModel.cpp
        # module StandardItem
        source/generated/StandardItem.h
        source/generated/StandardItem_wrappers.h
        source/generated/StandardItem_wrappers.cpp
        source/StandardItem.cpp
        # module SplitterHandle
        source/generated/SplitterHandle.h
        source/generated/SplitterHandle_wrappers.h
        source/generated/SplitterHandle_wrappers.cpp
        source/SplitterHandle.cpp
        # module Splitter
        source/generated/Splitter.h
        source/generated/Splitter_wrappers.h
        source/generated/Splitter_wrappers.cpp
        source/Splitter.cpp
        # module SpinBox
        source/generated/SpinBox.h
        source/generated/SpinBox_wrappers.h
        source/generated/SpinBox_wrappers.cpp
        source/SpinBox.cpp
        # module SortFilterProxyModel
        source/generated/SortFilterProxyModel.h
        source/generated/SortFilterProxyModel_wrappers.h
        source/generated/SortFilterProxyModel_wrappers.cpp
        source/SortFilterProxyModel.cpp
        # module Slider
        source/generated/Slider.h
        source/generated/Slider_wrappers.h
        source/generated/Slider_wrappers.cpp
        source/Slider.cpp
        # module SizePolicy
        source/generated/SizePolicy.h
        source/generated/SizePolicy_wrappers.h
        source/generated/SizePolicy_wrappers.cpp
        source/SizePolicy.cpp
        # module SizeF
        source/generated/SizeF.h
        source/generated/SizeF_wrappers.h
        source/generated/SizeF_wrappers.cpp
        source/SizeF.cpp
        # module Size
        source/generated/Size.h
        source/generated/Size_wrappers.h
        source/generated/Size_wrappers.cpp
        source/Size.cpp
        # module SessionManager
        source/generated/SessionManager.h
        source/generated/SessionManager_wrappers.h
        source/generated/SessionManager_wrappers.cpp
        source/SessionManager.cpp
        # module ScrollBar
        source/generated/ScrollBar.h
        source/generated/ScrollBar_wrappers.h
        source/generated/ScrollBar_wrappers.cpp
        source/ScrollBar.cpp
        # module ScrollArea
        source/generated/ScrollArea.h
        source/generated/ScrollArea_wrappers.h
        source/generated/ScrollArea_wrappers.cpp
        source/ScrollArea.cpp
        # module Screen
        source/generated/Screen.h
        source/generated/Screen_wrappers.h
        source/generated/Screen_wrappers.cpp
        source/Screen.cpp
        # module SafeReturn
        source/generated/SafeReturn.h
        source/generated/SafeReturn_wrappers.h
        source/generated/SafeReturn_wrappers.cpp
        source/SafeReturn.cpp
        # module RegularExpressionValidator
        source/generated/RegularExpressionValidator.h
        source/generated/RegularExpressionValidator_wrappers.h
        source/generated/RegularExpressionValidator_wrappers.cpp
        source/RegularExpressionValidator.cpp
        # module RegularExpression
        source/generated/RegularExpression.h
        source/generated/RegularExpression_wrappers.h
        source/generated/RegularExpression_wrappers.cpp
        source/RegularExpression.cpp
        # module Region
        source/generated/Region.h
        source/generated/Region_wrappers.h
        source/generated/Region_wrappers.cpp
        source/Region.cpp
        # module RectF
        source/generated/RectF.h
        source/generated/RectF_wrappers.h
        source/generated/RectF_wrappers.cpp
        source/RectF.cpp
        # module Rect
        source/generated/Rect.h
        source/generated/Rect_wrappers.h
        source/generated/Rect_wrappers.cpp
        source/Rect.cpp
        # module RadioButton
        source/generated/RadioButton.h
        source/generated/RadioButton_wrappers.h
        source/generated/RadioButton_wrappers.cpp
        source/RadioButton.cpp
        # module PushButton
        source/generated/PushButton.h
        source/generated/PushButton_wrappers.h
        source/generated/PushButton_wrappers.cpp
        source/PushButton.cpp
        # module ProgressBar
        source/generated/ProgressBar.h
        source/generated/ProgressBar_wrappers.h
        source/generated/ProgressBar_wrappers.cpp
        source/ProgressBar.cpp
        # module PolygonF
        source/generated/PolygonF.h
        source/generated/PolygonF_wrappers.h
        source/generated/PolygonF_wrappers.cpp
        source/PolygonF.cpp
        # module Polygon
        source/generated/Polygon.h
        source/generated/Polygon_wrappers.h
        source/generated/Polygon_wrappers.cpp
        source/Polygon.cpp
        # module PointF
        source/generated/PointF.h
        source/generated/PointF_wrappers.h
        source/generated/PointF_wrappers.cpp
        source/PointF.cpp
        # module Point
        source/generated/Point.h
        source/generated/Point_wrappers.h
        source/generated/Point_wrappers.cpp
        source/Point.cpp
        # module PlainTextEdit
        source/generated/PlainTextEdit.h
        source/generated/PlainTextEdit_wrappers.h
        source/generated/PlainTextEdit_wrappers.cpp
        source/PlainTextEdit.cpp
        # module Pixmap
        source/generated/Pixmap.h
        source/generated/Pixmap_wrappers.h
        source/generated/Pixmap_wrappers.cpp
        source/Pixmap.cpp
        # module PersistentModelIndex
        source/generated/PersistentModelIndex.h
        source/generated/PersistentModelIndex_wrappers.h
        source/generated/PersistentModelIndex_wrappers.cpp
        source/PersistentModelIndex.cpp
        # module Pen
        source/generated/Pen.h
        source/generated/Pen_wrappers.h
        source/generated/Pen_wrappers.cpp
        source/Pen.cpp
        # module PainterPath
        source/generated/PainterPath.h
        source/generated/PainterPath_wrappers.h
        source/generated/PainterPath_wrappers.cpp
        source/PainterPath.cpp
        # module Painter
        source/generated/Painter.h
        source/generated/Painter_wrappers.h
        source/generated/Painter_wrappers.cpp
        source/Painter.cpp
        # module PaintDevice
        source/generated/PaintDevice.h
        source/generated/PaintDevice_wrappers.h
        source/generated/PaintDevice_wrappers.cpp
        source/PaintDevice.cpp
        # module Object
        source/generated/Object.h
        source/generated/Object_wrappers.h
        source/generated/Object_wrappers.cpp
        source/Object.cpp
        # module ModelIndex
        source/generated/ModelIndex.h
        source/generated/ModelIndex_wrappers.h
        source/generated/ModelIndex_wrappers.cpp
        source/ModelIndex.cpp
        # module MimeData
        source/generated/MimeData.h
        source/generated/MimeData_wrappers.h
        source/generated/MimeData_wrappers.cpp
        source/MimeData.cpp
        # module MessageBox
        source/generated/MessageBox.h
        source/generated/MessageBox_wrappers.h
        source/generated/MessageBox_wrappers.cpp
        source/MessageBox.cpp
        # module MenuBar
        source/generated/MenuBar.h
        source/generated/MenuBar_wrappers.h
        source/generated/MenuBar_wrappers.cpp
        source/MenuBar.cpp
        # module Menu
        source/generated/Menu.h
        source/generated/Menu_wrappers.h
        source/generated/Menu_wrappers.cpp
        source/Menu.cpp
        # module MarginsF
        source/generated/MarginsF.h
        source/generated/MarginsF_wrappers.h
        source/generated/MarginsF_wrappers.cpp
        source/MarginsF.cpp
        # module Margins
        source/generated/Margins.h
        source/generated/Margins_wrappers.h
        source/generated/Margins_wrappers.cpp
        source/Margins.cpp
        # module MainWindow
        source/generated/MainWindow.h
        source/generated/MainWindow_wrappers.h
        source/generated/MainWindow_wrappers.cpp
        source/MainWindow.cpp
        # module Logging
        source/generated/Logging.h
        source/generated/Logging_wrappers.h
        source/generated/Logging_wrappers.cpp
        source/Logging.cpp
        # module ListView
        source/generated/ListView.h
        source/generated/ListView_wrappers.h
        source/generated/ListView_wrappers.cpp
        source/ListView.cpp
        # module LineEdit
        source/generated/LineEdit.h
        source/generated/LineEdit_wrappers.h
        source/generated/LineEdit_wrappers.cpp
        source/LineEdit.cpp
        # module LayoutItem
        source/generated/LayoutItem.h
        source/generated/LayoutItem_wrappers.h
        source/generated/LayoutItem_wrappers.cpp
        source/LayoutItem.cpp
        # module Layout
        source/generated/Layout.h
        source/generated/Layout_wrappers.h
        source/generated/Layout_wrappers.cpp
        source/Layout.cpp
        # module Label
        source/generated/Label.h
        source/generated/Label_wrappers.h
        source/generated/Label_wrappers.cpp
        source/Label.cpp
        # module KeySequence
        source/generated/KeySequence.h
        source/generated/KeySequence_wrappers.h
        source/generated/KeySequence_wrappers.cpp
        source/KeySequence.cpp
        # module ItemSelectionModel
        source/generated/ItemSelectionModel.h
        source/generated/ItemSelectionModel_wrappers.h
        source/generated/ItemSelectionModel_wrappers.cpp
        source/ItemSelectionModel.cpp
        # module ItemSelectionCommon
        source/generated/ItemSelectionCommon.h
        source/generated/ItemSelectionCommon_wrappers.h
        source/generated/ItemSelectionCommon_wrappers.cpp
        source/ItemSelectionCommon.cpp
        # module ItemSelection
        source/generated/ItemSelection.h
        source/generated/ItemSelection_wrappers.h
        source/generated/ItemSelection_wrappers.cpp
        source/ItemSelection.cpp
        # module Image
        source/generated/Image.h
        source/generated/Image_wrappers.h
        source/generated/Image_wrappers.cpp
        source/Image.cpp
        # module Icon
        source/generated/Icon.h
        source/generated/Icon_wrappers.h
        source/generated/Icon_wrappers.cpp
        source/Icon.cpp
        # module HeaderView
        source/generated/HeaderView.h
        source/generated/HeaderView_wrappers.h
        source/generated/HeaderView_wrappers.cpp
        source/HeaderView.cpp
        # module GuiApplication
        source/generated/GuiApplication.h
        source/generated/GuiApplication_wrappers.h
        source/generated/GuiApplication_wrappers.cpp
        source/GuiApplication.cpp
        # module GroupBox
        source/generated/GroupBox.h
        source/generated/GroupBox_wrappers.h
        source/generated/GroupBox_wrappers.cpp
        source/GroupBox.cpp
        # module GridLayout
        source/generated/GridLayout.h
        source/generated/GridLayout_wrappers.h
        source/generated/GridLayout_wrappers.cpp
        source/GridLayout.cpp
        # module GraphicsEffect
        source/generated/GraphicsEffect.h
        source/generated/GraphicsEffect_wrappers.h
        source/generated/GraphicsEffect_wrappers.cpp
        source/GraphicsEffect.cpp
        # module Gradient
        source/generated/Gradient.h
        source/generated/Gradient_wrappers.h
        source/generated/Gradient_wrappers.cpp
        source/Gradient.cpp
        # module Frame
        source/generated/Frame.h
        source/generated/Frame_wrappers.h
        source/generated/Frame_wrappers.cpp
        source/Frame.cpp
        # module FormLayout
        source/generated/FormLayout.h
        source/generated/FormLayout_wrappers.h
        source/generated/FormLayout_wrappers.cpp
        source/FormLayout.cpp
        # module Font
        source/generated/Font.h
        source/generated/Font_wrappers.h
        source/generated/Font_wrappers.cpp
        source/Font.cpp
        # module FileDialog
        source/generated/FileDialog.h
        source/generated/FileDialog_wrappers.h
        source/generated/FileDialog_wrappers.cpp
        source/FileDialog.cpp
        # module Event
        source/generated/Event.h
        source/generated/Event_wrappers.h
        source/generated/Event_wrappers.cpp
        source/Event.cpp
        # module Enums
        source/generated/Enums.h
        source/generated/Enums_wrappers.h
        source/generated/Enums_wrappers.cpp
        source/Enums.cpp
        # module Drag
        source/generated/Drag.h
        source/generated/Drag_wrappers.h
        source/generated/Drag_wrappers.cpp
        source/Drag.cpp
        # module DockWidget
        source/generated/DockWidget.h
        source/generated/DockWidget_wrappers.h
        source/generated/DockWidget_wrappers.cpp
        source/DockWidget.cpp
        # module Dir
        source/generated/Dir.h
        source/generated/Dir_wrappers.h
        source/generated/Dir_wrappers.cpp
        source/Dir.cpp
        # module Dialog
        source/generated/Dialog.h
        source/generated/Dialog_wrappers.h
        source/generated/Dialog_wrappers.cpp
        source/Dialog.cpp
        # module DateTime
        source/generated/DateTime.h
        source/generated/DateTime_wrappers.h
        source/generated/DateTime_wrappers.cpp
        source/DateTime.cpp
        # module Date
        source/generated/Date.h
        source/generated/Date_wrappers.h
        source/generated/Date_wrappers.cpp
        source/Date.cpp
        # module Cursor
        source/generated/Cursor.h
        source/generated/Cursor_wrappers.h
        source/generated/Cursor_wrappers.cpp
        source/Cursor.cpp
        # module CoreApplication
        source/generated/CoreApplication.h
        source/generated/CoreApplication_wrappers.h
        source/generated/CoreApplication_wrappers.cpp
        source/CoreApplication.cpp
        # module Completer
        source/generated/Completer.h
        source/generated/Completer_wrappers.h
        source/generated/Completer_wrappers.cpp
        source/Completer.cpp
        # module ComboBox
        source/generated/ComboBox.h
        source/generated/ComboBox_wrappers.h
        source/generated/ComboBox_wrappers.cpp
        source/ComboBox.cpp
        # module Color
        source/generated/Color.h
        source/generated/Color_wrappers.h
        source/generated/Color_wrappers.cpp
        source/Color.cpp
        # module CheckBox
        source/generated/CheckBox.h
        source/generated/CheckBox_wrappers.h
        source/generated/CheckBox_wrappers.cpp
        source/CheckBox.cpp
        # module CalendarWidget
        source/generated/CalendarWidget.h
        source/generated/CalendarWidget_wrappers.h
        source/generated/CalendarWidget_wrappers.cpp
        source/CalendarWidget.cpp
        # module Brush
        source/generated/Brush.h
        source/generated/Brush_wrappers.h
        source/generated/Brush_wrappers.cpp
        source/Brush.cpp
        # module BoxLayout
        source/generated/BoxLayout.h
        source/generated/BoxLayout_wrappers.h
        source/generated/BoxLayout_wrappers.cpp
        source/BoxLayout.cpp
        # module Application
        source/generated/Application.h
        source/generated/Application_wrappers.h
        source/generated/Application_wrappers.cpp
        source/Application.cpp
        # module Action
        source/generated/Action.h
        source/generated/Action_wrappers.h
        source/generated/Action_wrappers.cpp
        source/Action.cpp
        # module AbstractSpinBox
        source/generated/AbstractSpinBox.h
        source/generated/AbstractSpinBox_wrappers.h
        source/generated/AbstractSpinBox_wrappers.cpp
        source/AbstractSpinBox.cpp
        # module AbstractSlider
        source/generated/AbstractSlider.h
        source/generated/AbstractSlider_wrappers.h
        source/generated/AbstractSlider_wrappers.cpp
        source/AbstractSlider.cpp
        # module AbstractScrollArea
        source/generated/AbstractScrollArea.h
        source/generated/AbstractScrollArea_wrappers.h
        source/generated/AbstractScrollArea_wrappers.cpp
        source/AbstractScrollArea.cpp
        # module AbstractProxyModel
        source/generated/AbstractProxyModel.h
        source/generated/AbstractProxyModel_wrappers.h
        source/generated/AbstractProxyModel_wrappers.cpp
        source/AbstractProxyModel.cpp
        # module AbstractListModel
        source/generated/AbstractListModel.h
        source/generated/AbstractListModel_wrappers.h
        source/generated/AbstractListModel_wrappers.cpp
        source/AbstractListModel.cpp
        # module AbstractItemView
        source/generated/AbstractItemView.h
        source/generated/AbstractItemView_wrappers.h
        source/generated/AbstractItemView_wrappers.cpp
        source/AbstractItemView.cpp
        # module AbstractItemModel
        source/generated/AbstractItemModel.h
        source/generated/AbstractItemModel_wrappers.h
        source/generated/AbstractItemModel_wrappers.cpp
        source/AbstractItemModel.cpp
        # module AbstractItemDelegate
        source/generated/AbstractItemDelegate.h
        source/generated/AbstractItemDelegate_wrappers.h
        source/generated/AbstractItemDelegate_wrappers.cpp
        source/AbstractItemDelegate.cpp
        # module AbstractButton
        source/generated/AbstractButton.h
        source/generated/AbstractButton_wrappers.h
        source/generated/AbstractButton_wrappers.cpp
        source/AbstractButton.cpp

        # library implementation
        source/generated/Library.cpp
)

target_link_libraries(MinimalQtImpl PRIVATE Qt6::Widgets)
