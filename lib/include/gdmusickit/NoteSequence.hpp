#pragma once

#include "Note.hpp"
#include <regex>
#include <string>

namespace gdmusickit {

    // template <long FROM, long TO>
    class NoteSequence {
      public:
        NoteSequence() : notes{std::make_unique<std::vector<Note>>()} {}

        void addNote(Note note);
        friend std::ostream& operator<<(std::ostream& os,
                                        NoteSequence const& noteSequence);

        Note& operator[](int i) { return notes->at(i); }

        int size() const;
        //size_t size() const { return data.size(); }

        std::vector<Note>::iterator begin() { return notes->begin(); }
        std::vector<Note>::iterator end() { return notes->end(); }


        // inline static int FROM = 0;
        // inline static int TO = 1;

        // class iterator {
        //     long num = FROM;

        //   public:
        //     iterator(long _num = 0) : num(_num) {}
        //     iterator& operator++() {
        //         num = TO >= FROM ? num + 1 : num - 1;
        //         return *this;
        //     }
        //     iterator operator++(int) {
        //         iterator retval = *this;
        //         ++(*this);
        //         return retval;
        //     }
        //     bool operator==(iterator other) const { return num == other.num;
        //     } bool operator!=(iterator other) const { return !(*this ==
        //     other); } long operator*() { return num; }
        //     // iterator traits
        //     using difference_type = NoteSequence;
        //     using value_type = NoteSequence;
        //     using pointer = const NoteSequence*;
        //     using reference = const NoteSequence&;
        //     using iterator_category = std::forward_iterator_tag;
        //};
        // iterator begin() { return FROM; }
        // iterator end() { return TO >= FROM ? TO + 1 : TO - 1; }


/*
        // all this nonsense to be able to do a range based iterate
        template <typename T, typename C, size_t const Size>
        class NoteSequence_iterator_type {
          public:
            // iterator traits
            //http://eel.is/c++draft/iterator.traits#1
            //https://timsong-cpp.github.io/cppwp/n4659/#iterators
            using difference_type = NoteSequence;
            using value_type = NoteSequence;
            using pointer = const NoteSequence*;
            using reference = const NoteSequence&;
            using iterator_category = std::forward_iterator_tag;

            NoteSequence_iterator_type(C& collection, size_t const index)
                : index(index), collection(collection) {}

            bool operator!=(NoteSequence_iterator_type const& other) const {
                return index != other.index;
            }

            T const& operator*() const { return collection.at(index); }

            NoteSequence_iterator_type const& operator++() {
                ++index;
                return *this;
            }

          private:
            size_t index;
            C& collection;
        };
        template <typename T, size_t const Size>
        using NoteSequence_iterator =
            NoteSequence_iterator_type<T, NoteSequence, Size>;

        template <typename T, size_t const Size>
        using NoteSequence_const_iterator =
            NoteSequence_iterator_type<T, NoteSequence const, Size>;

        template <typename T, size_t const Size>
        inline NoteSequence_iterator<T, Size> begin(NoteSequence& collection);

        template <typename T, size_t const Size>
        inline NoteSequence_iterator<T, Size> end(NoteSequence& collection);

        template <typename T, size_t const Size>
        inline NoteSequence_const_iterator<T, Size>
        begin(NoteSequence const& collection) {
            return NoteSequence_const_iterator<T, Size>(collection, 0);
        }

        template <typename T, size_t const Size>
        inline NoteSequence_const_iterator<T, Size>
        end(NoteSequence const& collection) {
            return NoteSequence_const_iterator<T, Size>(collection,
                                                        collection.size());
        }
*/
      protected:
      private:
        std::unique_ptr<std::vector<Note>> notes;
    }; //

} // namespace gdmusickit