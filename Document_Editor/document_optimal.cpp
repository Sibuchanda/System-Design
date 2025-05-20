#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

// --- Abstract class ---
class DocumentElement{
   public:
     virtual string render()=0;
};


class TextElement : public DocumentElement{
    private:
      string text;

    public:
       TextElement(string txt){
        this->text=txt;
       }

       string render() override{
        return text;
       }
};

class ImageElement : public DocumentElement{
    private:
      string imagePath;
    public:
      ImageElement(string imgPath){
        this->imagePath=imgPath;
      }

      string render() override{
        return imagePath;
      }
};


class NewLineElement : public DocumentElement{
    public:
     string render() override{
        return "\n";
     }
};

class TabSpaceElement : public DocumentElement{
    public:
     string render() override{
        return "\t";
     }
};


class Document{
    private:
      vector<DocumentElement*> documents;

    public:
      void addElement(DocumentElement *element){
        documents.push_back(element);
      }

      string render(){
        string result;

        for(auto val:documents){
            result+=val->render();
        }
        return result;
      }
};


class Persistence{
 public:
   virtual void save(string data)=0;
};

class FileStorage : public Persistence {
public:
    void save(string data) override {
        ofstream outFile("document.txt");
        if (outFile) {
            outFile << data;
            outFile.close();
            cout << "Document saved to document.txt" << endl;
        } else {
            cout << "Error: Unable to open file for writing." << endl;
        }
    }
};

// ---  DBStorage implementation ---
class DBStorage : public Persistence {
public:
    void save(string data) override {
        cout<<"Saved data into Database"<<endl;
    }
};


// -- This is for managing client Interactons ----
class DocumentEditor{
 
    private:
      Document *doc;
      Persistence *storage;
      string allContents;

    public:
      DocumentEditor(Document *docs, Persistence *storage){
        this->doc = docs;
        this->storage = storage;
      }

      void addText(string txt){
        doc->addElement(new TextElement(txt));
      }

      void addImage(string imgPath){
        doc->addElement(new ImageElement(imgPath));
      }

      void addNewLine(){
        doc->addElement(new NewLineElement());
      }
      
        void addTabSpace() {
        doc->addElement(new TabSpaceElement());
    }

    string renderDocument(){
        if(allContents.empty()){
           allContents=doc->render();
        }
        return allContents;
    }

    void saveDocument(){
        storage->save(renderDocument());
    }

};


int main() {
    Document *document = new Document();
    Persistence *persistence = new FileStorage();

    DocumentEditor *editor = new DocumentEditor(document, persistence);

    // Simulate a client using the editor with common text formatting features.
    editor->addText("Hello, world!");
    editor->addNewLine();
    editor->addText("This is a real-world document editor example.");
    editor->addNewLine();
    editor->addTabSpace();
    editor->addText("Indented text after a tab space.");
    editor->addNewLine();
    editor->addImage("picture.jpg");

    // Render and display the final document.
    cout << editor->renderDocument() << endl;

    editor->saveDocument();

    return 0;
}