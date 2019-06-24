#include "gdmusickit/NoteSequence.hpp"
#include "gdmusickit/Pitch.hpp"
#include "gdmusickit/PitchFactory.hpp"

#include <algorithm>
#include <charconv> // from_char, to_char
#include <exception>
#include <iostream>
#include <regex>
#include <string>

namespace gdmusickit {
    //  NoteSequence::NoteSequence() noexcept {
    //     notes = std::make_unique<std::vector<Note>>();
    // }
    // int NoteSequence::begin(return 0);

    void NoteSequence::addNote(Note note) { notes->emplace_back(note); }

    // std::ostream& operator<<(std::ostream& os,
    //                          NoteSequence const& noteSequence) {
    //     for (note : NoteSequence) {
    //         os << "Pitch: " << note.pitch << " Start " << note.startBeat
    //            << " Duration " << note.duration << "\n";
    //     }

    //     return os;
    // }
    int NoteSequence::size() const { return notes->size(); }

    // // all this nonsense to be able to do a range based iterate
    // template <typename T, typename C, size_t const Size>
    // class NoteSequence_iterator_type {
    //   public:
    //   // iterator traits
    //     using difference_type = NoteSequence;
    //     using value_type = NoteSequence;
    //     using pointer = const NoteSequence*;
    //     using reference = const NoteSequence&;
    //     using iterator_category = std::forward_iterator_tag;

    //     NoteSequence_iterator_type(C& collection, size_t const index)
    //         : index(index), collection(collection) {}

    //     bool operator!=(NoteSequence_iterator_type const& other) const {
    //         return index != other.index;
    //     }

    //     T const& operator*() const { return collection.at(index); }

    //     NoteSequence_iterator_type const& operator++() {
    //         ++index;
    //         return *this;
    //     }

    //   private:
    //     size_t index;
    //     C& collection;
    // };
    // template <typename T, size_t const Size>
    // using NoteSequence_iterator =
    //     NoteSequence_iterator_type<T, NoteSequence, Size>;

    // template <typename T, size_t const Size>
    // using NoteSequence_const_iterator =
    //     NoteSequence_iterator_type<T, NoteSequence const, Size>;

    // template <typename T, size_t const Size>
    // inline NoteSequence_iterator<T, Size>
    // begin(NoteSequence& collection) {
    //     return NoteSequence_iterator<T, Size>(collection, 0);
    // }

    // template <typename T, size_t const Size>
    // inline NoteSequence_iterator<T, Size> 
    // end(NoteSequence& collection) {
    //     return NoteSequence_iterator<T, Size>(collection, collection.size());
    // }

    // template <typename T, size_t const Size>
    // inline NoteSequence_const_iterator<T, Size>
    // begin(NoteSequence const& collection) {
    //     return NoteSequence_const_iterator<T, Size>(collection, 0);
    // }

    // template <typename T, size_t const Size>
    // inline NoteSequence_const_iterator<T, Size>
    // end(NoteSequence const& collection) {
    //     return NoteSequence_const_iterator<T, Size>(collection,
    //                                                collection.size());
    // }
} // namespace gdmusickit