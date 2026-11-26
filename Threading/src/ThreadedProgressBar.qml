import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic
import DataProcessor

Item {
    id: root
    width: 600
    height: 50

    DataProcessor {
        id: dataProcessor
        itemName: root.objectName

        onProgressUpdated: (current, total) => {
            progressBar.value = current / total
        }

        onWorkFinished: {
            startBtn.enabled = true
            statusMessage.visible = true
            statusMessage.color = "green"
            statusMessage.text = qsTr("Finished")
        }
    }

    RowLayout {
        anchors.centerIn: parent
        width: parent.width
        spacing: 10

        Button {
            id: startBtn
            Layout.leftMargin: 10
            text: qsTr("Start processing")
            onClicked: {
                dataProcessor.startProcessing()
                enabled = false
                statusMessage.visible = false
                progressBar.value = 0.0
            }
        }

        ProgressBar {
            id: progressBar
            from: 0.0
            to: 1.0
            value: 0.0
            Layout.preferredWidth: 200
        }

        Text {
            id: currentProgress
            text: Math.round(progressBar.value * 100) + "%"
            Layout.rightMargin: 10
            visible: !statusMessage.visible
            Layout.preferredWidth: 100
        }

        Text {
            id: statusMessage
            Layout.rightMargin: 10
            visible: false
            Layout.preferredWidth: 100
        }
    }
}