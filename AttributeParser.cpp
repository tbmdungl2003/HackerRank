#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    cin.ignore();

    map<string, string> attribute_map;
    vector<string> tag_stack;

    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string first_word;
        ss >> first_word;

        if (first_word[1] == '/') {
            tag_stack.pop_back();
        } else {
            string tag_name = first_word.substr(1);
            if (tag_name.back() == '>') {
                tag_name.pop_back();
            }
            tag_stack.push_back(tag_name);

            string path = "";
            for (size_t k = 0; k < tag_stack.size(); ++k) {
                path += tag_stack[k] + (k == tag_stack.size() - 1 ? "" : ".");
            }

            string attr_name, eq, attr_value;
            while (ss >> attr_name >> eq >> attr_value) {
                attr_value.erase(remove(attr_value.begin(), attr_value.end(), '"'), attr_value.end());
                attr_value.erase(remove(attr_value.begin(), attr_value.end(), '>'), attr_value.end());
                string full_key = path + "~" + attr_name;
                attribute_map[full_key] = attr_value;
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        string query;
        cin >> query;
        if (attribute_map.count(query)) {
            cout << attribute_map[query] << endl;
        } else {
            cout << "Not Found!" << endl;
        }
    }
    return 0;
}
