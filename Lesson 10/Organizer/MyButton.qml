import QtQuick 2.15

BorderImage {
    signal clicked
    source: "qrc:/img/button.png"

    Text {
        id: _text
        text: "Add task"
        color: "white"
        anchors.centerIn: parent
    }

    MouseArea {
        anchors.fill: parent
        onClicked: parent.clicked()
    }
}
