# generated file - any edits will be overwritten!
cmake_minimum_required(VERSION 3.22)
project(MinimalQtImpl LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 20)
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
        support/CoreStuff.h
        support/NativeImplServer.h
        support/NativeImplServer.cpp
        support/result.h

        # util
        util/convert.h
        util/convert.cpp
        util/SignalStuff.h

        # module Window
        generated/Window.h
        generated/Window_wrappers.h
        generated/Window_wrappers.cpp
        Window.cpp
        # module Widget
        generated/Widget.h
        generated/Widget_wrappers.h
        generated/Widget_wrappers.cpp
        Widget.cpp
        # module Variant
        generated/Variant.h
        generated/Variant_wrappers.h
        generated/Variant_wrappers.cpp
        Variant.cpp
        # module Validator
        generated/Validator.h
        generated/Validator_wrappers.h
        generated/Validator_wrappers.cpp
        Validator.cpp
        # module Url
        generated/Url.h
        generated/Url_wrappers.h
        generated/Url_wrappers.cpp
        Url.cpp
        # module TreeView
        generated/TreeView.h
        generated/TreeView_wrappers.h
        generated/TreeView_wrappers.cpp
        TreeView.cpp
        # module Transform
        generated/Transform.h
        generated/Transform_wrappers.h
        generated/Transform_wrappers.cpp
        Transform.cpp
        # module ToolBar
        generated/ToolBar.h
        generated/ToolBar_wrappers.h
        generated/ToolBar_wrappers.cpp
        ToolBar.cpp
        # module Timer
        generated/Timer.h
        generated/Timer_wrappers.h
        generated/Timer_wrappers.cpp
        Timer.cpp
        # module TextOption
        generated/TextOption.h
        generated/TextOption_wrappers.h
        generated/TextOption_wrappers.cpp
        TextOption.cpp
        # module TextFormat
        generated/TextFormat.h
        generated/TextFormat_wrappers.h
        generated/TextFormat_wrappers.cpp
        TextFormat.cpp
        # module TextEdit
        generated/TextEdit.h
        generated/TextEdit_wrappers.h
        generated/TextEdit_wrappers.cpp
        TextEdit.cpp
        # module TextDocument
        generated/TextDocument.h
        generated/TextDocument_wrappers.h
        generated/TextDocument_wrappers.cpp
        TextDocument.cpp
        # module TextCursor
        generated/TextCursor.h
        generated/TextCursor_wrappers.h
        generated/TextCursor_wrappers.cpp
        TextCursor.cpp
        # module TextCharFormat
        generated/TextCharFormat.h
        generated/TextCharFormat_wrappers.h
        generated/TextCharFormat_wrappers.cpp
        TextCharFormat.cpp
        # module TabWidget
        generated/TabWidget.h
        generated/TabWidget_wrappers.h
        generated/TabWidget_wrappers.cpp
        TabWidget.cpp
        # module TabBar
        generated/TabBar.h
        generated/TabBar_wrappers.h
        generated/TabBar_wrappers.cpp
        TabBar.cpp
        # module StyledItemDelegate
        generated/StyledItemDelegate.h
        generated/StyledItemDelegate_wrappers.h
        generated/StyledItemDelegate_wrappers.cpp
        StyledItemDelegate.cpp
        # module StyleOptionViewItem
        generated/StyleOptionViewItem.h
        generated/StyleOptionViewItem_wrappers.h
        generated/StyleOptionViewItem_wrappers.cpp
        StyleOptionViewItem.cpp
        # module StyleOption
        generated/StyleOption.h
        generated/StyleOption_wrappers.h
        generated/StyleOption_wrappers.cpp
        StyleOption.cpp
        # module StatusBar
        generated/StatusBar.h
        generated/StatusBar_wrappers.h
        generated/StatusBar_wrappers.cpp
        StatusBar.cpp
        # module StandardItemModel
        generated/StandardItemModel.h
        generated/StandardItemModel_wrappers.h
        generated/StandardItemModel_wrappers.cpp
        StandardItemModel.cpp
        # module StandardItem
        generated/StandardItem.h
        generated/StandardItem_wrappers.h
        generated/StandardItem_wrappers.cpp
        StandardItem.cpp
        # module SplitterHandle
        generated/SplitterHandle.h
        generated/SplitterHandle_wrappers.h
        generated/SplitterHandle_wrappers.cpp
        SplitterHandle.cpp
        # module Splitter
        generated/Splitter.h
        generated/Splitter_wrappers.h
        generated/Splitter_wrappers.cpp
        Splitter.cpp
        # module SpinBox
        generated/SpinBox.h
        generated/SpinBox_wrappers.h
        generated/SpinBox_wrappers.cpp
        SpinBox.cpp
        # module SortFilterProxyModel
        generated/SortFilterProxyModel.h
        generated/SortFilterProxyModel_wrappers.h
        generated/SortFilterProxyModel_wrappers.cpp
        SortFilterProxyModel.cpp
        # module Slider
        generated/Slider.h
        generated/Slider_wrappers.h
        generated/Slider_wrappers.cpp
        Slider.cpp
        # module SizePolicy
        generated/SizePolicy.h
        generated/SizePolicy_wrappers.h
        generated/SizePolicy_wrappers.cpp
        SizePolicy.cpp
        # module SizeF
        generated/SizeF.h
        generated/SizeF_wrappers.h
        generated/SizeF_wrappers.cpp
        SizeF.cpp
        # module Size
        generated/Size.h
        generated/Size_wrappers.h
        generated/Size_wrappers.cpp
        Size.cpp
        # module SessionManager
        generated/SessionManager.h
        generated/SessionManager_wrappers.h
        generated/SessionManager_wrappers.cpp
        SessionManager.cpp
        # module ScrollBar
        generated/ScrollBar.h
        generated/ScrollBar_wrappers.h
        generated/ScrollBar_wrappers.cpp
        ScrollBar.cpp
        # module ScrollArea
        generated/ScrollArea.h
        generated/ScrollArea_wrappers.h
        generated/ScrollArea_wrappers.cpp
        ScrollArea.cpp
        # module Screen
        generated/Screen.h
        generated/Screen_wrappers.h
        generated/Screen_wrappers.cpp
        Screen.cpp
        # module SafeReturn
        generated/SafeReturn.h
        generated/SafeReturn_wrappers.h
        generated/SafeReturn_wrappers.cpp
        SafeReturn.cpp
        # module RegularExpressionValidator
        generated/RegularExpressionValidator.h
        generated/RegularExpressionValidator_wrappers.h
        generated/RegularExpressionValidator_wrappers.cpp
        RegularExpressionValidator.cpp
        # module RegularExpression
        generated/RegularExpression.h
        generated/RegularExpression_wrappers.h
        generated/RegularExpression_wrappers.cpp
        RegularExpression.cpp
        # module Region
        generated/Region.h
        generated/Region_wrappers.h
        generated/Region_wrappers.cpp
        Region.cpp
        # module RectF
        generated/RectF.h
        generated/RectF_wrappers.h
        generated/RectF_wrappers.cpp
        RectF.cpp
        # module Rect
        generated/Rect.h
        generated/Rect_wrappers.h
        generated/Rect_wrappers.cpp
        Rect.cpp
        # module RadioButton
        generated/RadioButton.h
        generated/RadioButton_wrappers.h
        generated/RadioButton_wrappers.cpp
        RadioButton.cpp
        # module PushButton
        generated/PushButton.h
        generated/PushButton_wrappers.h
        generated/PushButton_wrappers.cpp
        PushButton.cpp
        # module ProgressBar
        generated/ProgressBar.h
        generated/ProgressBar_wrappers.h
        generated/ProgressBar_wrappers.cpp
        ProgressBar.cpp
        # module PolygonF
        generated/PolygonF.h
        generated/PolygonF_wrappers.h
        generated/PolygonF_wrappers.cpp
        PolygonF.cpp
        # module Polygon
        generated/Polygon.h
        generated/Polygon_wrappers.h
        generated/Polygon_wrappers.cpp
        Polygon.cpp
        # module PointF
        generated/PointF.h
        generated/PointF_wrappers.h
        generated/PointF_wrappers.cpp
        PointF.cpp
        # module Point
        generated/Point.h
        generated/Point_wrappers.h
        generated/Point_wrappers.cpp
        Point.cpp
        # module PlainTextEdit
        generated/PlainTextEdit.h
        generated/PlainTextEdit_wrappers.h
        generated/PlainTextEdit_wrappers.cpp
        PlainTextEdit.cpp
        # module Pixmap
        generated/Pixmap.h
        generated/Pixmap_wrappers.h
        generated/Pixmap_wrappers.cpp
        Pixmap.cpp
        # module PersistentModelIndex
        generated/PersistentModelIndex.h
        generated/PersistentModelIndex_wrappers.h
        generated/PersistentModelIndex_wrappers.cpp
        PersistentModelIndex.cpp
        # module Pen
        generated/Pen.h
        generated/Pen_wrappers.h
        generated/Pen_wrappers.cpp
        Pen.cpp
        # module PainterPath
        generated/PainterPath.h
        generated/PainterPath_wrappers.h
        generated/PainterPath_wrappers.cpp
        PainterPath.cpp
        # module Painter
        generated/Painter.h
        generated/Painter_wrappers.h
        generated/Painter_wrappers.cpp
        Painter.cpp
        # module PaintDevice
        generated/PaintDevice.h
        generated/PaintDevice_wrappers.h
        generated/PaintDevice_wrappers.cpp
        PaintDevice.cpp
        # module Object
        generated/Object.h
        generated/Object_wrappers.h
        generated/Object_wrappers.cpp
        Object.cpp
        # module ModelIndex
        generated/ModelIndex.h
        generated/ModelIndex_wrappers.h
        generated/ModelIndex_wrappers.cpp
        ModelIndex.cpp
        # module MimeData
        generated/MimeData.h
        generated/MimeData_wrappers.h
        generated/MimeData_wrappers.cpp
        MimeData.cpp
        # module MessageBox
        generated/MessageBox.h
        generated/MessageBox_wrappers.h
        generated/MessageBox_wrappers.cpp
        MessageBox.cpp
        # module MenuBar
        generated/MenuBar.h
        generated/MenuBar_wrappers.h
        generated/MenuBar_wrappers.cpp
        MenuBar.cpp
        # module Menu
        generated/Menu.h
        generated/Menu_wrappers.h
        generated/Menu_wrappers.cpp
        Menu.cpp
        # module MarginsF
        generated/MarginsF.h
        generated/MarginsF_wrappers.h
        generated/MarginsF_wrappers.cpp
        MarginsF.cpp
        # module Margins
        generated/Margins.h
        generated/Margins_wrappers.h
        generated/Margins_wrappers.cpp
        Margins.cpp
        # module MainWindow
        generated/MainWindow.h
        generated/MainWindow_wrappers.h
        generated/MainWindow_wrappers.cpp
        MainWindow.cpp
        # module Logging
        generated/Logging.h
        generated/Logging_wrappers.h
        generated/Logging_wrappers.cpp
        Logging.cpp
        # module ListView
        generated/ListView.h
        generated/ListView_wrappers.h
        generated/ListView_wrappers.cpp
        ListView.cpp
        # module LineEdit
        generated/LineEdit.h
        generated/LineEdit_wrappers.h
        generated/LineEdit_wrappers.cpp
        LineEdit.cpp
        # module LayoutItem
        generated/LayoutItem.h
        generated/LayoutItem_wrappers.h
        generated/LayoutItem_wrappers.cpp
        LayoutItem.cpp
        # module Layout
        generated/Layout.h
        generated/Layout_wrappers.h
        generated/Layout_wrappers.cpp
        Layout.cpp
        # module Label
        generated/Label.h
        generated/Label_wrappers.h
        generated/Label_wrappers.cpp
        Label.cpp
        # module KeySequence
        generated/KeySequence.h
        generated/KeySequence_wrappers.h
        generated/KeySequence_wrappers.cpp
        KeySequence.cpp
        # module ItemSelectionModel
        generated/ItemSelectionModel.h
        generated/ItemSelectionModel_wrappers.h
        generated/ItemSelectionModel_wrappers.cpp
        ItemSelectionModel.cpp
        # module ItemSelectionCommon
        generated/ItemSelectionCommon.h
        generated/ItemSelectionCommon_wrappers.h
        generated/ItemSelectionCommon_wrappers.cpp
        ItemSelectionCommon.cpp
        # module ItemSelection
        generated/ItemSelection.h
        generated/ItemSelection_wrappers.h
        generated/ItemSelection_wrappers.cpp
        ItemSelection.cpp
        # module Image
        generated/Image.h
        generated/Image_wrappers.h
        generated/Image_wrappers.cpp
        Image.cpp
        # module Icon
        generated/Icon.h
        generated/Icon_wrappers.h
        generated/Icon_wrappers.cpp
        Icon.cpp
        # module HeaderView
        generated/HeaderView.h
        generated/HeaderView_wrappers.h
        generated/HeaderView_wrappers.cpp
        HeaderView.cpp
        # module GuiApplication
        generated/GuiApplication.h
        generated/GuiApplication_wrappers.h
        generated/GuiApplication_wrappers.cpp
        GuiApplication.cpp
        # module GroupBox
        generated/GroupBox.h
        generated/GroupBox_wrappers.h
        generated/GroupBox_wrappers.cpp
        GroupBox.cpp
        # module GridLayout
        generated/GridLayout.h
        generated/GridLayout_wrappers.h
        generated/GridLayout_wrappers.cpp
        GridLayout.cpp
        # module GraphicsEffect
        generated/GraphicsEffect.h
        generated/GraphicsEffect_wrappers.h
        generated/GraphicsEffect_wrappers.cpp
        GraphicsEffect.cpp
        # module Gradient
        generated/Gradient.h
        generated/Gradient_wrappers.h
        generated/Gradient_wrappers.cpp
        Gradient.cpp
        # module Frame
        generated/Frame.h
        generated/Frame_wrappers.h
        generated/Frame_wrappers.cpp
        Frame.cpp
        # module FormLayout
        generated/FormLayout.h
        generated/FormLayout_wrappers.h
        generated/FormLayout_wrappers.cpp
        FormLayout.cpp
        # module Font
        generated/Font.h
        generated/Font_wrappers.h
        generated/Font_wrappers.cpp
        Font.cpp
        # module FileDialog
        generated/FileDialog.h
        generated/FileDialog_wrappers.h
        generated/FileDialog_wrappers.cpp
        FileDialog.cpp
        # module Event
        generated/Event.h
        generated/Event_wrappers.h
        generated/Event_wrappers.cpp
        Event.cpp
        # module Enums
        generated/Enums.h
        generated/Enums_wrappers.h
        generated/Enums_wrappers.cpp
        Enums.cpp
        # module Drag
        generated/Drag.h
        generated/Drag_wrappers.h
        generated/Drag_wrappers.cpp
        Drag.cpp
        # module DockWidget
        generated/DockWidget.h
        generated/DockWidget_wrappers.h
        generated/DockWidget_wrappers.cpp
        DockWidget.cpp
        # module Dir
        generated/Dir.h
        generated/Dir_wrappers.h
        generated/Dir_wrappers.cpp
        Dir.cpp
        # module Dialog
        generated/Dialog.h
        generated/Dialog_wrappers.h
        generated/Dialog_wrappers.cpp
        Dialog.cpp
        # module DateTime
        generated/DateTime.h
        generated/DateTime_wrappers.h
        generated/DateTime_wrappers.cpp
        DateTime.cpp
        # module Date
        generated/Date.h
        generated/Date_wrappers.h
        generated/Date_wrappers.cpp
        Date.cpp
        # module Cursor
        generated/Cursor.h
        generated/Cursor_wrappers.h
        generated/Cursor_wrappers.cpp
        Cursor.cpp
        # module CoreApplication
        generated/CoreApplication.h
        generated/CoreApplication_wrappers.h
        generated/CoreApplication_wrappers.cpp
        CoreApplication.cpp
        # module Completer
        generated/Completer.h
        generated/Completer_wrappers.h
        generated/Completer_wrappers.cpp
        Completer.cpp
        # module ComboBox
        generated/ComboBox.h
        generated/ComboBox_wrappers.h
        generated/ComboBox_wrappers.cpp
        ComboBox.cpp
        # module Color
        generated/Color.h
        generated/Color_wrappers.h
        generated/Color_wrappers.cpp
        Color.cpp
        # module CheckBox
        generated/CheckBox.h
        generated/CheckBox_wrappers.h
        generated/CheckBox_wrappers.cpp
        CheckBox.cpp
        # module CalendarWidget
        generated/CalendarWidget.h
        generated/CalendarWidget_wrappers.h
        generated/CalendarWidget_wrappers.cpp
        CalendarWidget.cpp
        # module Brush
        generated/Brush.h
        generated/Brush_wrappers.h
        generated/Brush_wrappers.cpp
        Brush.cpp
        # module BoxLayout
        generated/BoxLayout.h
        generated/BoxLayout_wrappers.h
        generated/BoxLayout_wrappers.cpp
        BoxLayout.cpp
        # module Application
        generated/Application.h
        generated/Application_wrappers.h
        generated/Application_wrappers.cpp
        Application.cpp
        # module Action
        generated/Action.h
        generated/Action_wrappers.h
        generated/Action_wrappers.cpp
        Action.cpp
        # module AbstractSpinBox
        generated/AbstractSpinBox.h
        generated/AbstractSpinBox_wrappers.h
        generated/AbstractSpinBox_wrappers.cpp
        AbstractSpinBox.cpp
        # module AbstractSlider
        generated/AbstractSlider.h
        generated/AbstractSlider_wrappers.h
        generated/AbstractSlider_wrappers.cpp
        AbstractSlider.cpp
        # module AbstractScrollArea
        generated/AbstractScrollArea.h
        generated/AbstractScrollArea_wrappers.h
        generated/AbstractScrollArea_wrappers.cpp
        AbstractScrollArea.cpp
        # module AbstractProxyModel
        generated/AbstractProxyModel.h
        generated/AbstractProxyModel_wrappers.h
        generated/AbstractProxyModel_wrappers.cpp
        AbstractProxyModel.cpp
        # module AbstractListModel
        generated/AbstractListModel.h
        generated/AbstractListModel_wrappers.h
        generated/AbstractListModel_wrappers.cpp
        AbstractListModel.cpp
        # module AbstractItemView
        generated/AbstractItemView.h
        generated/AbstractItemView_wrappers.h
        generated/AbstractItemView_wrappers.cpp
        AbstractItemView.cpp
        # module AbstractItemModel
        generated/AbstractItemModel.h
        generated/AbstractItemModel_wrappers.h
        generated/AbstractItemModel_wrappers.cpp
        AbstractItemModel.cpp
        # module AbstractItemDelegate
        generated/AbstractItemDelegate.h
        generated/AbstractItemDelegate_wrappers.h
        generated/AbstractItemDelegate_wrappers.cpp
        AbstractItemDelegate.cpp
        # module AbstractButton
        generated/AbstractButton.h
        generated/AbstractButton_wrappers.h
        generated/AbstractButton_wrappers.cpp
        AbstractButton.cpp

        # library implementation
        generated/Library.cpp
)

target_link_libraries(MinimalQtImpl PRIVATE Qt6::Widgets)
