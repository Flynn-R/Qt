import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import Organizer 1.0

Window {
    width: 640
    height: 480
    minimumWidth: 640
    minimumHeight: 480
    visible: true
    title: qsTr("Organizer")

    onClosing: {
        _organizer.writeToFile()
    }

    RowLayout {
        id: _layout
        width: parent.width - 15
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: 5
        anchors.topMargin: 5

        TextField {
            id: _name
            width: parent.width / 3
            placeholderText: "Task name"
        }

        TextField {
            id: _deadline
            width: parent.width / 3
            placeholderText: "Deadline (dd.mm.yyyy)"
        }

        TextField {
            id: _progress
            width: parent.width / 3
            placeholderText: "Progress (from 0 to 10)"
        }
    }

//    Button {
//        anchors.top: _layout.bottom
//        anchors.topMargin: 10
//        anchors.horizontalCenter: parent.horizontalCenter
//        width: parent.width / 3
//        height: 50
//        text: "Write"

//        onClicked: {
//            _organizer.writeNewTask(_name.text, _deadline.text, _progress.text)
//            _name.text = ""
//            _deadline.text = ""
//            _progress.text = ""
//        }
//    }

    MyButton {
        id: _myButton
        anchors.top: _layout.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width / 3
        height: 50

        onClicked: {
            _organizer.addNewTask(_name.text, _deadline.text, _progress.text)
            _name.text = ""
            _deadline.text = ""
            _progress.text = ""
        }
    }

    Label {
        id: _status
        anchors.top: _myButton.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        text: _organizer.currentStatus()
        color: "black"
        font.family: "Helvetica"
        font.pixelSize: 15
    }

    Organizer {
        id: _organizer
        onFileLoaded: {
            if (!success)
                Qt.quit()
        }

        onIncorrectData: {
            if (arg)
                _status.text = _organizer.currentStatus()
            else
                _status.text = "Incorrect data was entered!"
        }
    }
}
