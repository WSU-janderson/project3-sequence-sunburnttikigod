class SequenceNode {
public:
    std::string item;
    std::shared_ptr<SequenceNode> next;
    std::weak_ptr<SequenceNode> prev;

    SequenceNode(const std::string &item) : item(item), next(nullptr), prev() {}
};

