import QtQuick
import QtQuick.Controls.Basic
import QtQuick.Layouts

Window {
    width: 640
    height: 160
    visible: true
    title: qsTr("Progress Bar Threading")

    Item {
        anchors.fill: parent
        ThreadedProgressBar {
            id: progressBar1
            objectName: "First progress bar"
        }
        ThreadedProgressBar {
            id: progressBar2
            anchors.top: progressBar1.bottom
            objectName: "Second progress bar"
        }
        ThreadedProgressBar {
            id: progressBar3
            anchors.top: progressBar2.bottom
            objectName: "Third progress bar"
        }
    }
}