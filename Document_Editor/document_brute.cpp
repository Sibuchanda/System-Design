#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

class DocumentEditor{
    private:
    vector<string> elements;
    string allDocuments;

    public:

     void addText(string txt){
        elements.push_back(txt);
     }

     void addImage(string imgPath){
        elements.push_back(imgPath);
     }

     string renderDocument(){
        if(allDocuments.empty()){
            string result;

            for(auto val : elements){
                if(val.size()>4 && (val.substr(val.size()-4)==".jpg" || val.substr(val.size() - 4) == ".png")){
                    result+="[Image:" + val + "]" + "\n";
                }else{
                    result+=val + '\n';
                }
            }
            allDocuments=result;
        }
        return allDocuments;
     }


     // --- Save File ----
     void saveToFile(){
        ofstream file("myDocument.txt");
        if(file.is_open()){
            file<<renderDocument();
            file.close();
            cout<<"Saved file as myDocument.txt"<<endl;
        }else{
            cout<<"Enable to open file for writting"<<endl;
        }

     }

};


int main(){
    DocumentEditor obj1;
    obj1.addText("This is my first System Design");
    obj1.addText("Hello, everyone..");
    // --- Add images into the file ---
    obj1.addImage("village.jpg");
    
    // -- Render the Document into global variable ---
    cout<<obj1.renderDocument()<<endl;

    // --Save to File --
    obj1.saveToFile();

    return 0;
}