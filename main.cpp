
#include <proton/messaging_handler.hpp>
#include <proton/container.hpp>
#include <proton/message.hpp>

#include <iostream>

class sender : public proton::messaging_handler {
    std::string m_connUrl;
    std::string m_topic;

public:
    sender(const std::string& url, const std::string& topic) : m_connUrl{url}, m_topic{topic} {}

    void on_container_start(proton::container& conn) override
    {
        std::cout << "Container start\n";
        conn.connect(m_connUrl);
    }

    void on_container_stop(proton::container& conn) override
    {
        std::cout << "Container stopped...\n";
    }

    void on_connection_open(proton::connection& conn) override
    {
        std::cout << "Connection established, open a sender for topic " << m_topic << "\n";
        conn.open_sender(m_topic);
    }

    void on_sendable(proton::sender &sender) override
    {
        std::cout << "Time to send data!\n";
        proton::message msg{"Hello there!"};
        sender.send(msg);
        sender.close();
        sender.connection().close();
    }
};

int main() {
    try {
        std::string connUrl = "//127.0.0.1:5672";
        std::string topic = "StarWars";

        sender sndr{connUrl, topic};

        proton::container(sndr).run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }

    return 0;
}