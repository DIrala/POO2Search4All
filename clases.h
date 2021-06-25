#ifndef CLASES_H
#define CLASES_H

#include <vector>
#include <iostream>
#include <string>
#include <filesystem>
#include <ostream>

using namespace std;


class Carpeta{
protected:
    vector<string> archivos; //contiene cada archivo
public:
    void push_back(string A){archivos.push_back(A);};
    vector<string>& get_Archivos(){return archivos;};
    void clear(){archivos.clear();};


};

class Entrada: public Carpeta{
public:
    void Mostrar();
};


class Salida: public Carpeta{
public:
    void Mostrar();
};

class Filtro {
private:
    string filtro;
    string param;
public:
    Filtro() = default;

    Filtro(string filtro, string param) : filtro{filtro}, param{param} {};

    void FiltroParcial(vector<string> &A) { //aqui se aplican filtros y por el & se editan en A
        if (filtro == "PorTipodeArchivo") { //falta completar
            //Trabaja con el vector A;
            for (auto i = begin(A); i != end(A); i++) {
                if (i == begin(A)) {

                }
            }
        } else if (filtro == "PorTerminoEnContenido") {
            size_t encontrar; //es para que esta variable sea igual que si returneamos el sizeof, regresa el tamano en bytes
            string str;
            for (auto i = begin(A); i != end(A); i++) {
                str = *i; //casteamos el *i (const char* a string)
                encontrar = str.find(param); //devuelve la primera ocurrencia de la secuencia de caracteres similares a los del, si no la encuentra, devuelve un npos
                if (encontrar == string::npos) //verifica que no haya encontrado un npos (que viene a ser el valor max. para un size_t, es decir el final del string)
                {
                    A.erase(i);
                    i--;
                };

            }
            //String que mas se repite
            //
        };
    };
};

class Menuu{
private:
    Entrada A;
    Salida B;
    vector<Filtro> Filtros; //le estoy quitando esto vector<Filtro*> Filtros;
    string Directorio;
public:
    /////   METODOS    ////
    void push_back(Filtro A){Filtros.push_back(A);};  //le estoy quitando esto void push_back(Filtro* A){Filtros.push_back(A);};

    void Mostrar(){
        if(Directorio[0] != '\0'){
            std::cout
            <<std::setw(30) << "Nombre" << ' '
                    <<std::setw(30) << "Tamaño(KB)" << ' '<<endl;

            for(auto i=begin(A.get_Archivos()); i!=end(A.get_Archivos()); i++){
                string nombre=*i;
                const size_t last_slash_idx = nombre.find_last_of("\\/");
                if (std::string::npos != last_slash_idx)
                {
                    nombre.erase(0, last_slash_idx + 1);
                }
                std::uintmax_t size = std::filesystem::file_size(*i);
                std::cout
                        <<std::setw(30)<< nombre << ' '
                        <<std::setw(30)<<size/1000.0<<endl;
            }
        }
        cout << "1. Ingresar directorio de carpeta" << endl;

        cout << "2. Refrescar el directorio de archivos en el que se encuentra actualmente" << endl;

        cout << "3. Agregar filtros deseados" << endl;

        cout << "4. Filtrar los datos" << endl;

        cout << "5. Salir" << endl;

        int opcion;
        cout << endl << "Ingrese el número correspondiente: "; cin >> opcion;
        switch (opcion){
            case 1:
                IngresarDirectorio();
                break;
            case 2:
                Refrescar();
                break;
            case 3:
                AgregarFiltro();
            case 4:
                Filtrar();
                break;
            case 5:
                cout << endl << "Gracias por usar Search4All!" << endl;
                break;
            default:
                cout << "No es ninguna de las opciones mostradas :(" << endl;
                Mostrar();
        };
    };

    void Refrescar(){
        cout << endl << "Por ahora no funciono :(" << endl;
        Mostrar();
        for (const auto & entry : std::filesystem::directory_iterator(Directorio))
            cout<<entry.path();
        cout<<"Carpeta actualizada"<<endl;
        Mostrar();
    };

    void IngresarDirectorio(){
        cout<<"Ingrese el directorio de la carpeta deseada:"<<endl;
        string dic;
        cin>>dic;
        Directorio=dic; //por ahora no hace nada
        for (const auto & file : std::filesystem::directory_iterator(Directorio))
            A.push_back(file.path().string());
        cout<<"Carpeta actualizada"<<endl;

        Mostrar();
    };

    void Filtrar(){
        for(auto i=begin(Filtros); i!=end(Filtros); i++){
            auto filtro=i; //auto filtro=*i;
            filtro->FiltroParcial(A.get_Archivos());
            cout << endl << "Empezando print de archivos" << endl;
            for(auto it=begin(A.get_Archivos()); it!=end(A.get_Archivos()); it++){
                cout<<*it<<endl;
            }
        }
        Mostrar();
    };
    void AgregarFiltro(){
        cout << endl << "¿Qué filtro quieres usar?" << endl;

        cout << "1. Filtro por tipo de archivo" << endl;

        cout << "2. Filtro por archivo que contenga cierto término" << endl;

        cout << "3. Filtro por archivo que empiece por cierto término" << endl;

        cout << "4. Filtro por archivo que termine con cierto término" << endl;

        cout << "5. Salir" << endl;

        int opc_filtro;
        cout << endl << "Ingrese el número correspondiente: "; cin >> opc_filtro;
        switch (opc_filtro){
            case 1: { //Luiss, cuando revises esto, aqui es para que elijan su opcion, esto luego ira hacia la clase de arriba, que dice filtro, ahi es donde tu ya implementas el filtro
                string parametro;
                cout << endl << "Tipo de archivo que quieres buscar: "; cin >> parametro; cout << endl;
                Filtro NumA("PorTipoDeArchivo", parametro); //aqui no le estoy poniendo *NumA
                Filtros.push_back(NumA); //o *NumA?
                Mostrar();
                break;
            }
            case 2: {
                string parametro;
                cout << endl << "Termino que quieres buscar: "; cin >> parametro; cout << endl;
                Filtro NumB("PorTerminoEnContenido", parametro);
                Filtros.push_back(NumB); //o *NumB?
                Mostrar();
                break;
            }
            case 3: {
                cout << endl << "Próximamente!" << endl;
                Mostrar();
                break;
            }
            case 4:{
                cout << endl << "Próximamente!" << endl;
                Mostrar();
                break;
            }
            case 5: {
                cout << endl << "Regresando al Menú" << endl;
                break;
            }
            default: {
                cout << "No es ninguna de las opciones mostradas :(" << endl;
                Mostrar();
            }
        }
    };
};

#endif






