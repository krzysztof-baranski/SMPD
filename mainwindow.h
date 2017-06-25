#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <fstream>
#include <QCheckBox>
#include <QFileDialog>
#include <QtCore>
#include <QtGui>
#include <QMessageBox>

#include"database.h"
#include"object.h"
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/lu.hpp>

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <math.h>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    bool loadFile(const std::string &fileName);
    void updateDatabaseInfo();
    void saveFile(const std::string &fileName);

    void FSupdateButtonState(void);
    void FSsetButtonState(bool state);



private slots:
    void on_FSpushButtonOpenFile_clicked();

    void on_FSpushButtonCompute_clicked();

    void on_FSpushButtonSaveFile_clicked();

    void on_PpushButtonSelectFolder_clicked();


    void on_CpushButtonOpenFile_clicked();

    void on_CpushButtonSaveFile_clicked();

    void on_CpushButtonTrain_clicked();

    void on_CpushButtonExecute_clicked();

    float computeNN();

    float computekNN(int k);

    float computeNM();

    //boolean compare(const Object &i,const Object &j);

    boolean contains(int i,int tab[],int count);

    //vector<Object> randKElements(vector<Object> tab, int k);

    //float countDistance(const float a,const float b);

    float calculateFisher();

    void calculateFisher(map<string, boost::numeric::ublas::matrix<float>>& XiAi, map<string, boost::numeric::ublas::matrix<float>>& averages , int loopCounter, int rowCounter, int howManyDig);
    float calculateSFS(map<string, boost::numeric::ublas::matrix<float>>& XiAi, map<string, boost::numeric::ublas::matrix<float>>& averages,int rowNumber);

    float determinant_sign(const  boost::numeric::ublas::permutation_matrix<std::size_t>& pm);

    float determinant(boost::numeric::ublas::matrix<float>& m );

    void on_pushButton_clicked();

    void on_CpushButtonClear_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    vector<float> countFourierDescriptors(std::vector<cv::Point> allPoints, std::string path);

    void writeToFile (std::string, QString);

private:
    Ui::MainWindow *ui;

private:
    Database database;
    std::vector<Object> shuffledObjects;
};

#endif // MAINWINDOW_H
