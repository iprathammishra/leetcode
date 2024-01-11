// 12. **XML Encoding:** Since XML is very verbose, you are given a way of encoding it where each tag gets mapped to a pre-defined integer value. The language/grammer is as follows:

// Element --> Tag Attributes END Children END
// Attribute --> Tag Value
// END --> 0
// Tag --> some predefined mapping to int
// Value --> string value

// For example, the following XML might be converted into the compressed string below (assuming a mapping of family -> 1, person -> 2, firstName -> 3, lastName -> 4, state -> 5).

// ```xml
// <family lastname="McDowel" state="CA">
//     <person firstName-"Gayle">Some Message</person>
// </family>
// ```

// Becomes:
// 1 4 McDowell 5 CA 0 2 3 Gayle 0 Some Message 0 0

// Write code to print the encoded version of an XML element (passed in Element and Attribute objects).
#include <iostream>
#include <unordered_map>
#include <vector>
std::unordered_map<std::string, int> tagMapping = {
    {"family" , 1},
    {"person", 2},
    {"firstName", 3},
    {"lastName", 4},
    {"state", 5},
};
class Attribute {
    public:
        std::string tag;
        std::string value;

        Attribute(const std::string& t, const std::string& v) : tag(t), value(v) {}
};
class Element {
    public:
        std::string tag;
        std::string value;
        std::vector<Element> children;
        std::vector<Attribute> attributes;

        Element(const std::string& t) : tag(t) {}

        std::string encode() const {
            std::string result = std::to_string(tagMapping.at(tag)) + " ";

            for (const auto& attribute: attributes)
                result += std::to_string(tagMapping.at(attribute.tag)) + " " + attribute.value + " ";
            result += "0 ";

            for (const auto& child : children)
                result += child.encode();
            
            result += value + " ";
            return result + "0 ";
        }
};
int main()
{
    Element family("family");
    family.attributes.emplace_back("lastName", "McDowel");
    family.attributes.emplace_back("state", "CA");

    Element person("person");
    person.attributes.emplace_back("firstName", "Gayle");
    person.value = "Some Message";

    family.children.push_back(person);

    std::string encodedXML = family.encode();
    std::cout << "Encoded XML: " << encodedXML << std::endl;
    return 0;
}