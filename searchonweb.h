#ifndef SERCHONWEB_H_
#define SERCHONWEB_H_

#include <QTranslator>
#include <QApplication>
#include "plugininterface.h"

#define PLUGIN_NAME    "Search On Web"
#define PLUGIN_VERSION "0.0.4"

class SearchOnWeb : public PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.quardCRT.PluginInterface" FILE "./plugininterface/plugininterface.json")
    Q_INTERFACES(PluginInterface)

public:
    SearchOnWeb() : m_mainMenu(nullptr) {}
    virtual ~SearchOnWeb() {}

    int init(QMap<QString, QString> params, QWidget *parent);

    void setLanguage(const QLocale &language,QApplication *app);
    void retranslateUi();
    QString name() { return PLUGIN_NAME; }
    QString version() { return PLUGIN_VERSION; }

    QMap<QString,void *> metaObject() {
        QMap<QString,void *> ret;
        ret.insert("QMenu", (void *)m_mainMenu);
        return ret;
    }

    QMenu *terminalContextMenu(QString selectedText, QString workingDirectory, QMenu *parentMenu) {Q_UNUSED(selectedText);Q_UNUSED(workingDirectory);Q_UNUSED(parentMenu); return nullptr;}
    QList<QAction *> terminalContextAction(QString selectedText, QString workingDirectory, QMenu *parentMenu);

private:
    QMenu *m_mainMenu;
    QActionGroup *actionGroup;
    QAction *googleAction;
    QAction *baiduAction;
    QAction *bingAction;
    QAction *githubAction;
    QAction *stackoverflowAction;
};

#endif /* SERCHONWEB_H_ */
