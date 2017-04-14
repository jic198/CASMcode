#ifndef CASM_ConfigEnumEquivalents
#define CASM_ConfigEnumEquivalents

#include "casm/misc/cloneable_ptr.hh"
#include "casm/symmetry/PermuteIterator.hh"
#include "casm/symmetry/EnumEquivalents.hh"
#include "casm/clex/Configuration.hh"

namespace CASM {

  class Supercell;
  class FillSupercell;

  /// \brief Enumerate all equivalent Configurations in a Supercell, as generated
  ///        by Supercell factor group symmetry
  ///
  /// - The 'begin' Configuration is always the canonical form
  /// - Note that there may be other Configurations equivalent by primitive
  ///   Structure factor group symmetry that can not be generated by permutations
  ///   using the Supercell factor group symmetry
  ///
  /// \ingroup EnumEquivalents
  /// \ingroup ConfigEnumGroup
  ///
  class ConfigEnumEquivalents : public EnumEquivalents<Configuration, PermuteIterator> {

    // -- Required -------------------

  public:

    ConfigEnumEquivalents(const Configuration &config);

    ConfigEnumEquivalents(const Configuration &config, PermuteIterator begin, PermuteIterator end);

    std::string name() const override {
      return enumerator_name;
    }

    static const std::string enumerator_name;

  };

}

#endif
