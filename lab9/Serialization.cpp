//
// Created by Grove on 2017-05-04.
//

#include "Serialization.h"

namespace academia{
    Building::Building(int id_, const std::string &name_, const std::vector<std::reference_wrapper<const Serializable>> &rooms_) : id_(id_), name_(name_),
                                                                                             rooms_(rooms_) {}
    std::string Room::TypeToString(Room::Type type) const {
        switch(type) {
            case Type::CLASSROOM :
                return "CLASSROOM";
            case Type::COMPUTER_LAB :
                return "COMPUTER_LAB";
            case Type ::LECTURE_HALL :
                return "LECTURE_HALL";
        }
    }


    Room::Room(int id_, const std::string &name_, Room::Type type_) : id_(id_), name_(name_), type_(type_) {}

    void Building::Serialize(Serializer *ser) const {
        ser->Header("building");
        ser->IntegerField("id",id_);
        ser->StringField("name",name_);
        ser->ArrayField("rooms",rooms_);
        ser->Footer("building");
    }

    void Room::Serialize(Serializer *ser) const {
        ser->Header("room");
        ser->IntegerField("id", id_);
        ser->StringField("name", name_);
        ser->StringField("type", TypeToString(type_));
        ser->Footer("room");
    }

    Building::Building() {

    }

    Building::~Building() {

    }

    Serializer::Serializer() {    }

    Serializer::~Serializer() {    }



    Room::Room() {}

    void XmlSerializer::IntegerField(const std::string &field_name, int value) {

    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value) {

    }

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {

    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value) {

    }

    void XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {

    }
    void XmlSerializer::ArrayField(const std::string &field_name,
                                   const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
    }

    void XmlSerializer::Header(const std::string &object_name) {

    }

    void XmlSerializer::Footer(const std::string &object_name) {

    }

    void JsonSerializer::IntegerField(const std::string &field_name, int value) {
        string value_str = to_string(value);
        *out_  << "\"" << field_name << "\": " << value_str << ", ";
    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value) {
        string value_str = to_string(value);

        *out_  << "\"" << field_name << "\": " << value_str << ", ";

    }

    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
        if(field_name == "type")
        {
            *out_  << "\"" << field_name << "\": \"" << value << "\"";
        }
        else{
            *out_ << "\"" << field_name << "\": \"" << value << "\"" << ", ";
        }
    }

    void JsonSerializer::BooleanField(const std::string &field_name, bool value) {
        string value_str = to_string(value);
        *out_  << "\"" << field_name << "\": " << value_str << ", ";
    }

    void JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        *out_ << field_name;
    }


    void JsonSerializer::ArrayField(const std::string &field_name,
                                    const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
        *out_ << "\"" << field_name << "\": [";
        int i = 0;
        for(const Serializable &n : value)
        {
            i++;
            JsonSerializer serial{out_};
            n.Serialize(&serial);
            if(i != value.size()){
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

    XmlSerializer::XmlSerializer() {

    }

    XmlSerializer::~XmlSerializer() {

    }

    JsonSerializer::JsonSerializer() {

    }

    JsonSerializer::~JsonSerializer() {

    }
}