#ifndef HLTrigger_HLTfilters_TriggerExpressionL1uGTReader_h
#define HLTrigger_HLTfilters_TriggerExpressionL1uGTReader_h

#include <vector>
#include <string>

#include "HLTrigger/HLTcore/interface/TriggerExpressionEvaluator.h"

namespace triggerExpression {

  class L1uGTReader : public Evaluator {
  public:
    L1uGTReader(const std::string& pattern) : m_pattern{pattern}, m_triggers{}, m_initialised{false} {}

    bool operator()(const Data& data) const override;

    void init(const Data& data) override;

    void dump(std::ostream& out) const override;

  private:
    std::string m_pattern;
    std::vector<std::pair<std::string, unsigned int>> m_triggers;
    bool m_initialised;
  };

}  // namespace triggerExpression

#endif  // HLTrigger_HLTfilters_TriggerExpressionL1uGTReader_h
