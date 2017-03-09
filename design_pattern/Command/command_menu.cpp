#include <iostream>
using namespace std;
#include <time.h>

static string clipboard;

class Log
{
private:
    static int count;
public:
    static int get_count()
    {
        return count;
    }
    static void log()
    {
        count++;
    }
};

int Log::count = 0;

class Document 
{
private:
    string page, oldpage;
    string name;
public:
    Document(string name)
    {
        this->name = name;
    }
    void paste()
    {
        oldpage = page;
        page += clipboard + '\n';
    }
    void restore()
    {
        page = oldpage;
    }
    void print()
    {
        time_t now;
        time(&now);
        cout << "File " << name << "at " << ctime(&now) << endl << page;
    }
};

class ICommand
{
public:
    virtual void execute() = 0;
    virtual void redo() = 0;
    virtual void undo() = 0;
};

class Paste: public ICommand
{
private:
    Document* doc;
public:
    Paste(Document* d)
    {
        doc = d;
    }
    void execute()
    {
        Log::log();
        doc->paste();
    }
    void redo()
    {
        Log::log();
        doc->paste();
    }
    void undo()
    {
        Log::log();
        doc->restore();
    }
};

class Print: public ICommand
{
private:
    Document* doc;
public:
    Print(Document* d)
    {
        doc = d;
    }
    void execute()
    {
        Log::log();
        doc->print();
    }
    void redo()
    {
        Log::log();
        doc->print();
    }
    void undo()
    {
        Log::log();
        cout << "Cannot undo a print " << endl;
    }
};

int main()
{
    Document* document = new Document("Greetings");
    ICommand* paste = new Paste(document);
    ICommand* print = new Print(document);

    clipboard = "hello everyone";
    paste->execute();
    print->execute();
    paste->undo();

    clipboard = "Bonjour, mes asmis";
    paste->execute();
    clipboard = "Guten morgen, meine Fredundo";
    paste->redo();
    print->execute();
    print->undo();

    cout << "Logged " << Log::get_count() << " commands" << endl;

    delete print;
    delete paste;
    delete document;
    return 0;
}
