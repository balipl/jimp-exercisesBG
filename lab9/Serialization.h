//
// Created by Grove on 2017-05-04.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <string>
#include <vector>
#include <ostream>
#include <functional>

using std::string;
using std::to_string;


namespace academia {

    class Serializer;

    class Serializable {
    public:
        virtual void Serialize(Serializer *ser) const =0;
    };

    class Serializer {
    public:
        Serializer();

        Serializer(std::ostream *out) : out_(out) {};

        ~Serializer();


        virtual void IntegerField(const std::string &field_name, int value) =0;

        virtual void DoubleField(const std::string &field_name, double value) =0;

        virtual void StringField(const std::string &field_name, const std::string &value) =0;

        virtual void BooleanField(const std::string &field_name, bool value) =0;

        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value) =0;

        virtual void ArrayField(const std::string &field_name,
                                const std::vector<std::reference_wrapper<const academia::Serializable>> &value) =0;

        virtual void Header(const std::string &object_name) =0;

        virtual void Footer(const std::string &object_name) =0;

    protected:
        std::ostream *out_;
    };


    class Room : public Serializable {
    public:

        enum class Type {
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };


        Room();

        Room(int id_, const std::string &name_, Type type_);


        void Serialize(Serializer *ser) const override;

        std::string TypeToString(Type type) const;

    private:
        int id_;
        std::string name_;
        Type type_;

    };


    class Building : public Serializable {
    public:
        Building();

        virtual ~Building();

        Building(int id_, const std::string &name_,
                 const std::vector<std::reference_wrapper<const Serializable>> &rooms_);


        void Serialize(Serializer *ser) const override;

    private:
        int id_;
        std::string name_;
        std::vector<std::reference_wrapper<const Serializable>> rooms_;
    };


    class XmlSerializer : public Serializer {
    public:
        XmlSerializer();

        XmlSerializer(std::ostream *out) : Serializer(out) {};

        virtual ~XmlSerializer();


        void IntegerField(const std::string &field_name, int value) override;

        void DoubleField(const std::string &field_name, double value) override;

        void StringField(const std::string &field_name, const std::string &value) override;

        void BooleanField(const std::string &field_name, bool value) override;

        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;

        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;

        void Header(const std::string &object_name) override;

        void Footer(const std::string &object_name) override;
    };

    class JsonSerializer : public Serializer {
    public:
        JsonSerializer();

        JsonSerializer(std::ostream *out) : Serializer(out) {};

        virtual ~JsonSerializer();


        void IntegerField(const std::string &field_name, int value) override;

        void DoubleField(const std::string &field_name, double value) override;

        void StringField(const std::string &field_name, const std::string &value) override;

        void BooleanField(const std::string &field_name, bool value) override;

        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;

        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;

        void Header(const std::string &object_name) override;

        void Footer(const std::string &object_name) override;
    };

}
#endif //JIMP_EXERCISES_SERIALIZATION_H
