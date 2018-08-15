import QtQuick 2.9
import QtQuick.Controls 1.4
import QtQuick.Controls 2.4 as Controls
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.3

// Ui界面
ApplicationWindow {
    id            : appWidget;
    visible       : true;  title         : qsTr("五子棋");
    minimumWidth  : 734;   minimumHeight : 545;
    maximumWidth  : 734;   maximumHeight : 545;

    signal start();
    signal resign();
    signal rollback(int n);
    signal choiceModel(int md);
    signal mouseClickEvent(int index);

    /*************互斥组***************/
    ExclusiveGroup { id : modeGroup; }                // 游戏模式互斥组

    // 菜单栏
    menuBar: MenuBar {
        Menu {
            title : qsTr("游戏选项");
            MenuItem {
                id          : startAction;
                text        : qsTr("开始游戏");
                onTriggered : { start(); clearBoard(); }
            }
            MenuSeparator {}
            MenuItem {
                id          : rollbackAction;
                text        : qsTr("悔棋");
                onTriggered : rollback(1);
            }
            MenuItem {
                id          : resignAction;
                text        : qsTr("认输");
                onTriggered : {}
            }
            MenuSeparator {}
            MenuItem {
                id          : exitAction;
                text        : qsTr("退出游戏");
                onTriggered : Qt.quit();
            }
        }

        Menu {
            title: qsTr("对战模式");
            MenuItem {
                id             : pvpAction;
                text           : qsTr("双人对战");
                checkable      : true;
                checked        : true;
                exclusiveGroup : modeGroup;
                onTriggered    : choiceModel(1);
            }
            MenuItem {
                id             : pveAction;
                text           : qsTr("人机对战");
                checkable      : true;
                exclusiveGroup : modeGroup;
                onTriggered    : choiceModel(2);
            }
        }

        Menu {
            title       : qsTr("游戏设置");
        }
    }

    // 棋盘Ui
    Rectangle {
        width  : 534;  height : 535;
        color  : "transparent";

        // Ui背景
        Image {
            x      : 0;    y      : 0;
            width  : 534;  height : 535;
            source : "qrc:/qml/images/board.png"
        }

        // 网格布局，每个格子一个棋子
        Grid {
            id      : grid;
            x       : 4;   y       : 4;
            rows    : 15;  columns : 15;
            spacing : 0;
            Repeater {
                model : 225
                // 宽: 57 高: 57 无背景色
                Image { width: 35; height: 35; source: ""; }
            }
        }

        // 获取鼠标的点击
        MouseArea {
            anchors.fill : parent
            onClicked : {
                var index = parseInt(mouseX/35) + parseInt(mouseY/35) * 15;
                if(index >= 0 && index < 225) {
                    mouseClickEvent(index);
                }
            }
        }
    }

    // 显示信息的区域
    Rectangle {
        id    : frame;
        x     : 534;   y      : 0;
        width : 200;   height : parent.height - 10;
        clip  : true;  focus  : true;
        border.color : "black";

        Keys.onUpPressed   : vbar.decrease();
        Keys.onDownPressed : vbar.increase();

        TextEdit {
            id     : msg;
            height : contentHeight;
            width  : frame.width - vbar.width;
            y      : -vbar.position * msg.height;

            readOnly         : true;
            font.family      : "Microsoft YaHei";
            font.pointSize   : 11;
            textFormat       : TextEdit.RichText;
            wrapMode         : TextEdit.WrapAnywhere;
            selectByKeyboard : true;
            selectByMouse    : true;
            font.wordSpacing : 0;

            MouseArea {
                anchors.fill : msg;
                onWheel   : {
                    if (wheel.angleDelta.y > 0) vbar.decrease();
                    else vbar.increase();
                }
                onClicked : { msg.forceActiveFocus(); }
            }
        }

        Controls.ScrollBar {
            id     : vbar;
            width  : 10;
            size   : frame.height / msg.height;
            active : hovered || pressed;

            orientation    : Qt.Vertical;
            hoverEnabled   : true;
            anchors.top    : parent.top;
            anchors.right  : parent.right;
            anchors.bottom : parent.bottom;
        }
    }

    // 显示消息
    function pushMessages(type, message)
    {
        var str = qsTr("<p style='margin=0'><font color='%1' >[%2] %3</font></p>");
        // 系统消息
        if(type === 0) str = str.arg("red").arg("系  统").arg(message);
        else if(type === 1) str = str.arg("yellow").arg("玩  家").arg(message);
        else if(type === 2) str = str.arg("blue").arg("  我  ").arg(message);
        msg.append(str);
    }

    // 点击棋盘
    function clickBoard(next, chess, prev)
    {
        // next位置的棋子是一个刚被点击的棋子
        // prev位置的棋子是上次被点击的棋子
        if(next !== -1) {
            var nObj    = grid.children[next];
            nObj.source = qsTr("qrc:/qml/images/new_%1.png").arg(chess);
            if(prev !== -1) {
                var pObj    = grid.children[prev];
                var img     = String(pObj.source);
                img         = img.replace(/new_(\d+)/g, "$1");
                pObj.source = img;
            }
        }
    }

    // 移除之前一个棋子
    function rollbackBoard(next, prev)
    {
        if(next !== -1) {
            grid.children[next].source = "";
            if(prev !== -1) {
                var obj    = grid.children[prev];
                var img    = String(obj.source);
                img        = img.replace(/(\d+)/g, "new_$1");
                obj.source = img;
            }
        }
    }

    function clearBoard()
    {
        var obj = grid.children;

        for(var i = 0; i < obj.length; ++ i) {
            obj[i].source = "";
        }
    }

}
