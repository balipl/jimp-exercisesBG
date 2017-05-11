//
// Created by Grove on 2017-05-04.
//

#include "Serialization.h"

namespace academia {

    Serializer::Serializer() {}

    Serializer::~Serializer() {}


    Building::Building() {}

    Building::Building(int id_, const std::string &name_,
                       const std::vector<std::reference_wrapper<const Serializable>> &rooms_) : id_(id_), name_(name_),
                                                                                                rooms_(rooms_) {}

    Building::~Building() {}

    void Building::Serialize(Serializer *ser) const {
        ser->Header("building");
        ser->IntegerField("id", id_);
        ser->StringField("name", name_);
        ser->ArrayField("rooms", rooms_);
        ser->Footer("building");
    }


    Room::Room() {}

    Room::Room(int id_, const std::string &name_, Room::Type type_) : id_(id_), name_(name_), type_(type_) {}

    std::string Room::TypeToString(Room::Type type) const {
        switch (type) {
            case Type::CLASSROOM :
                return "CLASSROOM";
            case Type::COMPUTER_LAB :
                return "COMPUTER_LAB";
            case Type::LECTURE_HALL :
                return "LECTURE_HALL";
        }
    }

    void Room::Serialize(Serializer *ser) const {
        ser->Header("room");
        ser->IntegerField("id", id_);
        ser->StringField("name", name_);
        ser->StringField("type", TypeToString(type_));
        ser->Footer("room");
    }


    XmlSerializer::XmlSerializer() {}

    XmlSerializer::~XmlSerializer() {}

    void XmlSerializer::IntegerField(const std::string &field_name, int value) {
        string value_string = to_string(value);
        *out_ << "<" << field_name << ">" << value_string << "<\\" << field_name << ">";
    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value) {
        string value_string = to_string(value);
        *out_ << "<" << field_name << ">" << value_string << "<\\" << field_name << ">";
    }

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
        *out_ << "<" << field_name << ">" << value << "<\\" << field_name << ">";
    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value) {
        string value_string = to_string(value);
        *out_ << "<" << field_name << ">" << value_string << "<\\" << field_name << ">";
    }

    void XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        *out_ << "<" << field_name << ">";
        value.Serialize(this);
        *out_ << "<\\" << field_name << ">";
    }

    void XmlSerializer::ArrayField(const std::string &field_name,
                                   const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
        *out_ << "<" << field_name << ">";



        for (const Serializable &n : value) {


            n.Serialize(this);
        }
        *out_ << "<\\" << field_name << ">";

    }

    void XmlSerializer::Header(const std::string &object_name) {
        *out_ << "<" << object_name << ">";
    }

    void XmlSerializer::Footer(const std::string &object_name) {
        *out_ << "<\\" << object_name << ">";
    }


    JsonSerializer::JsonSerializer() {}

    JsonSerializer::~JsonSerializer() {}


    void JsonSerializer::IntegerField(const std::string &field_name, int value) {
        string value_str = to_string(value);
        *out_ << "\"" << field_name << "\": " << value_str << ", ";
    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value) {
        string value_str = to_string(value);

        *out_ << "\"" << field_name << "\": " << value_str << ", ";

    }

    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
        if (field_name == "type") {
            *out_ << "\"" << field_name << "\": \"" << value << "\"";
        } else {
            *out_ << "\"" << field_name << "\": \"" << value << "\"" << ", ";
        }
    }

    void JsonSerializer::BooleanField(const std::string &field_name, bool value) {
        string value_str = to_string(value);
        *out_ << "\"" << field_name << "\": " << value_str << ", ";
    }

    void JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        *out_ << "\"" << field_name << "\": ";
        value.Serialize(this);
        *out_ << ", ";
    }


    void JsonSerializer::ArrayField(const std::string &field_name,
                                    const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
        *out_ << "\"" << field_name << "\": [";
        int i = 0;
        for (const Serializable &n : value) {
            i++;

            n.Serialize(this);
            if (i != value.size()) {
                *out_ << ", ";
            }

        }
        *out_ << "]";

    }

    void JsonSerializer::Header(const std::string &object_name) {
        *out_ << "{";
    }

    void JsonSerializer::Footer(const std::string &object_name) {
        *out_ << "}";
    }


}