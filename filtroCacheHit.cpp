#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
#include<string>

using namespace std;
using namespace cv;

void neg(string nome);

int main(){
    clock_t tempo = clock();
	string imgs[16] = {"im1.jpg","im2.jpg","im3.jpg","im4.jpg","im5.jpg","im6.jpg","im7.jpg","im8.jpg","im9.jpg","im10.jpg","im11.jpg","im12.jpg","im13.jpg","im14.jpg","im15.jpg","im16.jpg"};
	int tam = sizeof(imgs)/sizeof(imgs[0]);
    for(int f=0;f<tam;f++){
    	neg(imgs[f]);
    }

    cout<<"tempo de processamento:"<<(double)(clock() - tempo)/CLOCKS_PER_SEC<<endl;
    return 0;
}

void neg(string nome) {
	Mat imagem;

    imagem = imread(nome,IMREAD_COLOR);		//Le a imagem de entrada e converte ela para uma matriz de 3 canais (BGR)

    if(!imagem.data){
        cout<<"Aconteceu erros com a leitura da imagem!"<<endl;
    }


    for(int i = 0; i<imagem.rows; i++)
        for(int j=0; j<imagem.cols; j++){
                imagem.at<Vec3b>(i,j)[0] = 255 - imagem.at<Vec3b>(i,j)[0];    //Blue
                imagem.at<Vec3b>(i,j)[1] = 255 - imagem.at<Vec3b>(i,j)[1];	  //Green
                imagem.at<Vec3b>(i,j)[2] = 255 - imagem.at<Vec3b>(i,j)[2];	  //Red
        }

    namedWindow("Janela",WINDOW_NORMAL);
    imshow("Janela",imagem);
    //waitKey(300);
}


