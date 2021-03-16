#include <stdexcept>
#include <optional>
#include <map>
#include <vector>
#include <list>
#include <iostream>

template <typename Key1, typename Key2, typename Value>
class BiMap {
public:
    // Вставить значение, указав один или оба ключа.
    // Генерирует исключение std::invalid_argument("some text") в случае,
    // если оба ключа пусты, либо один из ключей уже имеется в хранилище.
    void Insert(const std::optional<Key1>& key1,
                const std::optional<Key2>& key2,
                const Value& value) {
        size_t refs = 0;
        if (key1.has_value()) {
            ++refs;
        }
        if (key2.has_value()) {
            ++refs;
        }
        values_.push_back({value, refs, false});
        if (key1.has_value()) {
            index1_[key1.value()] = --values_.end();
        }
        if (key2.has_value()) {
            index2_[*key2] = --values_.end();
        }
    }

//    template <class Key>
//    static bool EraserFromByKey(const Key &key, const std::map<Key, Value*> &map) {
//        auto it = map.find(key);
//        if (it == map.end()) {
//            return false;
//        }
//        map.erase(it);
//    }

    bool EraseByPrimaryKey(const Key1& key) {
        auto it = index1_.find(key);
        if (it == index1_.end()) {
            return false;
        }
        if (--it->second->refs == 0) {
            values_.erase(it->second);
        }
        index1_.erase(it);
        return true;
    }

    template <class C, class Key>
    static C& GetterFromByKey(const Key &key, const std::map<Key, Value*> &map) {
        auto it = map.find(key);
        if (it != map.end()) {
            return *((*it).second);
        }
        throw std::out_of_range("");
    }

    // Получить значение по ключу первого типа.
    // Генерирует исключение std::out_of_range("some text")
    // в случае отсутствия ключа (как и функция at в std::map).
    Value& GetByPrimaryKey(const Key1& key) {
        auto it = index1_.find(key);
        if (it != index1_.end()) {
            if (it->second->deleted) {
                if (--it->second->refs == 0) {
                    values_.erase(it->second);
                }
                throw std::out_of_range("");
            }
            return it->second->value;
        }
        throw std::out_of_range("");
//        return GetterFromByKey<Value>(key, index1_);
    }
//    const Value& GetByPrimaryKey(const Key1& key) const {
//        return GetterFromByKey<const Value>(key, index1_);
//    }

    // Аналогичная функция для ключа второго типа.
    Value& GetBySecondaryKey(const Key2& key) {
        auto it = index2_.find(key);
        if (it != index2_.end()) {
            return it->second->value;
        }
        throw std::out_of_range("");
//        return GetterFromByKey<Value>(key, index2_);
    }
//    const Value& GetBySecondaryKey(const Key2& key) const {
//        return GetterFromByKey<const Value>(key, index2_);
//    }

private:
    struct Node {
        Value value;
        size_t refs;
        bool deleted;
    };
    std::list<Node> values_;
    std::map<Key1, typename decltype(values_)::iterator> index1_;
    std::map<Key2, typename decltype(values_)::iterator> index2_;
};

int main() {
    BiMap<int, int, int> m;
    m.Insert(1, 2, 5);
    m.GetByPrimaryKey(1) = 6;
    if (m.GetBySecondaryKey(2) == 6) {
        std::cout << "OK\n";
    }
//    m.Insert(2, 3, 6);
//    if (m.GetBySecondaryKey(2) == 6) {
//        std::cout << "OK\n";
//    }
    m.EraseByPrimaryKey(1);

    m.GetBySecondaryKey(2) = 7;
    m.GetByPrimaryKey(1) = 8;
}
