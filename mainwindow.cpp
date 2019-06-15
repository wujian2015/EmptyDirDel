#include <QtWidgets>

#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_m_pSetRootDirBtn_clicked()
{
	QString strDirPath = QFileDialog::getExistingDirectory(this, ("Select Dir"), "D:/BaiduNetdiskDownload");

	m_strRootPath.clear();
	m_strDelList.clear();
	if (!strDirPath.isEmpty())
	{
		ui->m_pDirPathLE->setText(strDirPath);
		
		getEmptyDir(strDirPath, m_strDelList);

		ui->m_pOutPutTE->setPlainText(m_strDelList.join("\n"));

		ui->m_pOutPutTE->append("--------------------------------------------------------------------------------------------------------------------");
		
		ui->m_pOutPutTE->append(QString("Analyzed！Total Count: %1").arg(m_strDelList.size()));

		m_strRootPath = strDirPath;
		ui->m_pDelBtn->setEnabled(true);
	}
	else
	{
		ui->m_pDelBtn->setEnabled(false);
	}
}

void MainWindow::on_m_pDelBtn_clicked()
{
	foreach(const QString &s, m_strDelList)	
		QDir(s).rmpath(s);

	ui->m_pOutPutTE->append("Delete Finished!");
}

void MainWindow::getEmptyDir(const QDir &strDir, QStringList &sl)
{	
	foreach(const QFileInfo &f, strDir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name))
		if (!QDir(f.absoluteFilePath()).isEmpty())
			getEmptyDir(f.absoluteFilePath(), sl);
		else
			sl << f.absoluteFilePath();	
}
