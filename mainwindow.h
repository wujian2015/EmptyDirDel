#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QDir>

namespace Ui {
class MainWindow;
}

/*!
 * \class	MainWindow
 * \brief	The application's main form.
 * \author	Cuipf
 * \date	2019/6/15
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
	void on_m_pSetRootDirBtn_clicked();
	void on_m_pDelBtn_clicked();

private:
	/*!
	 * \fn	void MainWindow::getEmptyDir(const QDir &strDir, QStringList &sl);
	 * \brief	Gets empty dir abs path.
	 * \author	Cuipf
	 * \date	2019/6/15
	 * \param 		  	strDir	The dir.
	 * \param [in,out]	sl	  	The sl.
	 */
	void getEmptyDir(const QDir &strDir, QStringList &sl);	

	QString m_strRootPath;
	QStringList m_strDelList;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
