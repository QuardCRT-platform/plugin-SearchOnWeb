
#include "searchonweb.h"

#include <QMap>
#include <QActionGroup>
#include <QDesktopServices>

int SearchOnWeb::init(QMap<QString, QString> params, QWidget *parent)
{
    m_mainMenu = new QMenu(tr("Search On Web"), parent);

    actionGroup = new QActionGroup(m_mainMenu);
    actionGroup->setExclusive(true);

    googleAction = new QAction(tr("Google"), actionGroup);
    googleAction->setCheckable(true);
    m_mainMenu->addAction(googleAction);

    baiduAction = new QAction(tr("Baidu"), actionGroup);
    baiduAction->setCheckable(true);
    m_mainMenu->addAction(baiduAction);

    bingAction = new QAction(tr("Bing"), actionGroup);
    bingAction->setCheckable(true);
    m_mainMenu->addAction(bingAction);

    githubAction = new QAction(tr("Github"), actionGroup);
    githubAction->setCheckable(true);
    m_mainMenu->addAction(githubAction);

    stackoverflowAction = new QAction(tr("Stackoverflow"), actionGroup);
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

    if(checkedAction == googleAction)
    {
        QAction *googleAction = new QAction(tr("Google"), parentMenu);
        googleAction->setData("https://www.google.com/search?q=" + selectedText);
        connect(googleAction, &QAction::triggered, [=](){
            QDesktopServices::openUrl(QUrl(googleAction->data().toString()));
        });
        return QList<QAction *>() << googleAction;
    }
    else if(checkedAction == baiduAction)
    {
        QAction *baiduAction = new QAction(tr("Baidu"), parentMenu);
        baiduAction->setData("https://www.baidu.com/s?wd=" + selectedText);
        connect(baiduAction, &QAction::triggered, [=](){
            QDesktopServices::openUrl(QUrl(baiduAction->data().toString()));
        });
        return QList<QAction *>() << baiduAction;
    }
    else if(checkedAction == bingAction)
    {
        QAction *bingAction = new QAction(tr("Bing"), parentMenu);
        bingAction->setData("https://bing.com/search?q=" + selectedText);
        connect(bingAction, &QAction::triggered, [=](){
            QDesktopServices::openUrl(QUrl(bingAction->data().toString()));
        });
        return QList<QAction *>() << bingAction;
    }
    else if(checkedAction == githubAction)
    {
        QAction *githubAction = new QAction(tr("Github"), parentMenu);
        githubAction->setData("https://github.com/search?q=" + selectedText);
        connect(githubAction, &QAction::triggered, [=](){
            QDesktopServices::openUrl(QUrl(githubAction->data().toString()));
        });
        return QList<QAction *>() << githubAction;
    }
    else if(checkedAction == stackoverflowAction)
    {
        QAction *stackoverflowAction = new QAction(tr("Stackoverflow"), parentMenu);
        stackoverflowAction->setData("https://stackoverflow.com/search?q=" + selectedText);
        connect(stackoverflowAction, &QAction::triggered, [=](){
            QDesktopServices::openUrl(QUrl(stackoverflowAction->data().toString()));
        });
        return QList<QAction *>() << stackoverflowAction;
    }

    return QList<QAction *>();
}


void SearchOnWeb::setLanguage(const QLocale &language,QApplication *app) {
    static QTranslator *qtTranslator = nullptr;
    if(qtTranslator == nullptr) {
        qtTranslator = new QTranslator(app);
    } else {
        app->removeTranslator(qtTranslator);
        delete qtTranslator;
        qtTranslator = new QTranslator(app);
    }
    switch(language.language()) {
    case QLocale::Chinese:
        if(qtTranslator->load(":/lang/searchonweb_zh_CN.qm"))
            app->installTranslator(qtTranslator);
        break;
    default:
    case QLocale::English:
        if(qtTranslator->load(":/lang/searchonweb_en_US.qm"))
            app->installTranslator(qtTranslator);
        break;
    }
}

void SearchOnWeb::retranslateUi() {
    m_mainMenu->setTitle(tr("Search On Web"));
    googleAction->setText(tr("Google"));
    baiduAction->setText(tr("Baidu"));
    bingAction->setText(tr("Bing"));
    githubAction->setText(tr("Github"));
    stackoverflowAction->setText(tr("Stackoverflow"));
}
