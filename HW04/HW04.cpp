#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std; // namespace std 사용

class Book {
public:
    string title;
    string author;
    int have;

    Book(const string& title, const string& author) //생성자 초기화 제목/작가
        : title(title), author(author), have(3) {
    }
};

class BookManager {
private:
    vector<Book> books; // 책 목록 저장
    map<string, string> info;
public:

    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author)); // push_back 사용
        info[title] = author;
        cout << "책이 추가되었습니다: " << title << " by " << author << endl;
    }

    void displayAllBooks() const {
        if (books.empty()) { // 벡터 books에 저장된 값이 없으면 출력
            cout << "현재 등록된 책이 없습니다." << endl;
            return;
        }

        cout << "현재 도서 목록:" << endl;
        for (size_t i = 0; i < books.size(); i++) { // 일반적인 for문 사용
            cout << "- " << books[i].title << " by " << books[i].author
                << " 보유량 : " << books[i].have << "권" << endl;
        }
    }
    void search_by_title(const string& bookname) {
        for (auto& book : books) {
            if (book.title == bookname) {
                cout << "책 제목 : " << book.title << "작가 이름 : " << book.author
                    << " 보유량 : " << book.have << "권" << endl;
                if (book.have == 0) {
                    cout << "보유 재고 없음 대여 불가!!!" << endl;
                }
                else {
                    cout << "1. 대여" << endl;
                    cout << "2. 뒤로" << endl;
                }
                int input;
                cout << "선택: ";
                cin >> input;
                if (input == 1) {
                    cout << "대여가 완료되었습니다." << endl;
                    book.have -= 1;
                }
            }
        }
    }

    void search_by_name(const string& name) {
        for (auto& book : books) {
            if (book.author == name) {
                cout << "\n책 제목 : " << book.title << "작가 이름 : " << book.author
                    << " 보유량 : " << book.have << "권" << endl;
                if (book.have == 0) {
                    cout << "보유 재고 없음 대여 불가!!!" << endl;
                }
                else {
                    cout << "1. 대여" << endl;
                    cout << "2. 뒤로" << endl;
                }
                int input;
                cin >> input;
                if (input == 1) {
                    cout << "대여가 완료되었습니다." << endl;
                    book.have -= 1;
                }
            }
        }
    }
    void returnBook(const string& info) {
        for (auto& book : books) {
            if (book.title == info) {
                cout << "반납이 완료되었습니다." << endl;
                book.have += 1;
            }
            else if (book.author == info) {
                cout << "반납이 완료되었습니다." << endl;
                book.have += 1;
            }
        }
    }
};

int main() {
    BookManager manager;

    // 도서관 관리 프로그램의 기본 메뉴를 반복적으로 출력하여 사용자 입력을 처리합니다.
    // 프로그램 종료를 선택하기 전까지 계속 동작합니다.
    while (true) {
        cout << "\n도서관 관리 프로그램" << endl;
        cout << "1. 책 추가" << endl; // 책 정보를 입력받아 책 목록에 추가
        cout << "2. 모든 책 출력" << endl; // 현재 책 목록에 있는 모든 책 출력
        cout << "3. 제목으로 찾기" << endl;
        cout << "4. 작가 이름으로 찾기" << endl;
        cout << "5. 책 반납" << endl;
        cout << "6. 종료" << endl; // 프로그램 종료
        cout << "선택: ";

        int choice; // 사용자의 메뉴 선택을 저장
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            // 1번 선택: 책 추가
            // 사용자로부터 책 제목과 저자명을 입력받아 BookManager에 추가합니다.
            string title, author;
            cout << "책 제목: ";
            getline(cin, title); // 제목 입력 (공백 포함)
            cout << "책 저자: ";
            getline(cin, author); // 저자명 입력 (공백 포함)
            manager.addBook(title, author); // 입력받은 책 정보를 추가
        }
        else if (choice == 2) {
            // 2번 선택: 모든 책 출력
            // 현재 BookManager에 저장된 책 목록을 출력합니다.
            manager.displayAllBooks();
        }
        else if (choice == 3) {
            string title;
            cout << "책 제목: ";
            getline(cin, title);
            manager.search_by_title(title);
        }
        else if (choice == 4) {
            string name;
            cout << "작가 이름: ";
            getline(cin, name);
            manager.search_by_name(name);
        }
        else if (choice == 5) {
            string info;
            cout << "제목 or 작가: ";
            getline(cin, info);
            manager.returnBook(info);
        }
        else if (choice == 6) {
            // 3번 선택: 종료
            // 프로그램을 종료하고 사용자에게 메시지를 출력합니다.
            cout << "프로그램을 종료합니다." << endl;
            break; // while 루프 종료
        }
        else {
            // 잘못된 입력 처리
            // 메뉴에 없는 번호를 입력했을 경우 경고 메시지를 출력합니다.
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;

        }
    }

    return 0; // 프로그램 정상 종료
}
