import QtQuick 2.15

// Не имею ни малейшего понятия как это должно работать
// Прошу, подскажите в комментарии как это можно реализовать (второе задание)

Window {
    width: 600
    height: 500
    minimumWidth: 600
    minimumHeight: 500

    TableView {
        id: _tableView
        model: model
    }
}
