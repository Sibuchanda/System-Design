#include<iostream>
#include<string>
#include<vector>

using namespace std;

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
      string url;
    public:
    ImageElement(string txt){
        this->url=txt;
    }
      string render() override{
         return url;
      }
};


class Document{
     private:
       vector<DocumentElement*> elements;
    public:
      void addElement(DocumentElement *doc){
         elements.push_back(doc);
      }
      const vector<DocumentElement*> &getElements(){
        return elements;
      }
};


class Renderer{
    private:
     string contents;
     Document *doc;
    public:
       Renderer(Document *doc){
          this->doc=doc;
       }
    string render(){
        contents.clear();
        for(auto it : doc->getElements()){
            contents+=it->render();
            contents+="\n";
        }
        return contents;
    }
};

class Persistance{
    public:
     virtual void save(string contents)=0;
};

class SaveToFile: public Persistance{
    public:
     void save(string contents) override{
       cout<<"Contents are saved into file.\n";
     }
};

class SaveToDB: public Persistance{
    public:
     void save(string contents) override{
        cout<<"Contents are save into DB\n";
     }
};


class DocumentEditor{
    private:
     Document *doc;
     Persistance *db;
     Renderer *r;

    public:
     DocumentEditor(Document *doc, Persistance *db, Renderer *r){
        this->doc=doc;
        this->db=db;
        this->r=r;
     }

     void addText(string text){
        doc->addElement(new TextElement(text));
     }
     void addImage(string url){
        doc->addElement(new ImageElement(url));
     }
     
    void saveDocument(string s){
         db->save(s); 
    }
    string render(){
        return r->render();
    }

};

int main(){
    Document *doc = new Document();
    Persistance *db = new SaveToFile();
    Renderer *r = new Renderer(doc);

    DocumentEditor *editor = new DocumentEditor(doc,db,r);
    editor->addText("Hello");
    editor->addImage("image.jpg");
    cout<<editor->render();
    editor->saveDocument(editor->render()); 
}