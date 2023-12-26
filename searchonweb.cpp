
#include "searchonweb.h"

#include <QMap>
#include <QActionGroup>
#include <QDesktopServices>

int SearchOnWeb::init(QMap<QString, QString> params, QWidget *parent)
{
    m_mainMenu = new QMenu("Search On Web", parent);

    actionGroup = new QActionGroup(m_mainMenu);
    actionGroup->setExclusive(true);

    QAction *googleAction = new QAction("Google", actionGroup);
    googleAction->setCheckable(true);
    m_mainMenu->addAction(googleAction);

    QAction *baiduAction = new QAction("Baidu", actionGroup);
    baiduAction->setCheckable(true);
    m_mainMenu->addAction(baiduAction);

    QAction *bingAction = new QAction("Bing", actionGroup);
    bingAction->setCheckable(true);
    m_mainMenu->addAction(bingAction);

    QAction *githubAction = new QAction("Github", actionGroup);
    githubAction->setCheckable(true);
    m_mainMenu->addAction(githubAction);

    QAction *stackoverflowAction = new QAction("Stackoverflow", actionGroup);
    stackoverflowAction->setCheckable(true);
    m_mainMenu->addAction(stackoverflowAction);

    googleAction->setChecked(true);

    return 0;
}

QList<QAction *> SearchOnWeb::terminalContextAction(QString selectedText, QString workingDirectory, QMenu *parentMenu)
{
    if(selectedText.isEmpty())
    {
        return QList<QAction *>();
    }

    QAction *checkedAction = actionGroup->checkedAction();
    if (checkedAction == nullptr)
    {
        return QList<QAction *>();
    }

    if(checkedAction->text() == "Google")
    {
        QAction *googleAction = new QAction("Google", parentMenu);
        googleAction->setData("https://www.google.com/search?q=" + selectedText);
        connect(googleAction, &QAction::triggered, [=](){
            QDesktopServices::openUrl(QUrl(googleAction->data().toString()));
        });
        return QList<QAction *>() << googleAction;
    }
    else if(checkedAction->text() == "Baidu")
    {
        QAction *baiduAction = new QAction("Baidu", parentMenu);
        baiduAction->setData("https://www.baidu.com/s?wd=" + selectedText);
        connect(baiduAction, &QAction::triggered, [=](){
            QDesktopServices::openUrl(QUrl(baiduAction->data().toString()));
        });
        return QList<QAction *>() << baiduAction;
    }
    else if(checkedAction->text() == "Bing")
    {
        QAction *bingAction = new QAction("Bing", parentMenu);
        bingAction->setData("https://bing.com/search?q=" + selectedText);
        connect(bingAction, &QAction::triggered, [=](){
            QDesktopServices::openUrl(QUrl(bingAction->data().toString()));
        });
        return QList<QAction *>() << bingAction;
    }
    else if(checkedAction->text() == "Github")
    {
        QAction *githubAction = new QAction("Github", parentMenu);
        githubAction->setData("https://github.com/search?q=" + selectedText);
        connect(githubAction, &QAction::triggered, [=](){
            QDesktopServices::openUrl(QUrl(githubAction->data().toString()));
        });
        return QList<QAction *>() << githubAction;
    }
    else if(checkedAction->text() == "Stackoverflow")
    {
        QAction *stackoverflowAction = new QAction("Stackoverflow", parentMenu);
        stackoverflowAction->setData("https://stackoverflow.com/search?q=" + selectedText);
        connect(stackoverflowAction, &QAction::triggered, [=](){
            QDesktopServices::openUrl(QUrl(stackoverflowAction->data().toString()));
        });
        return QList<QAction *>() << stackoverflowAction;
    }

    return QList<QAction *>();
}
