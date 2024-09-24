#include <gtkmm.h>
#include <iostream>

class NameCombinerWindow : public Gtk::Window
{
public:
    NameCombinerWindow()
    {
        set_title("Solution 4");
        set_border_width(10);

        vbox.set_spacing(5);
        add(vbox);

        vbox.pack_start(first_name_label);
        first_name_label.set_text("First name");
        vbox.pack_start(first_name_entry);

        vbox.pack_start(last_name_label);
        last_name_label.set_text("Last name");
        vbox.pack_start(last_name_entry);

        combine_button.set_label("Combine names");
        combine_button.set_sensitive(false); 
        vbox.pack_start(combine_button);

        vbox.pack_start(combined_name_label);

        first_name_entry.signal_changed().connect(sigc::mem_fun(*this, &NameCombinerWindow::on_name_entry_changed));
        last_name_entry.signal_changed().connect(sigc::mem_fun(*this, &NameCombinerWindow::on_name_entry_changed));
        combine_button.signal_clicked().connect(sigc::mem_fun(*this, &NameCombinerWindow::on_combine_button_clicked));

        show_all_children();
    }

protected:
    void on_name_entry_changed()
    {
        bool has_first_name = !first_name_entry.get_text().empty();
        bool has_last_name = !last_name_entry.get_text().empty();

        combine_button.set_sensitive(has_first_name && has_last_name);
    }

    void on_combine_button_clicked()
    {
        std::string first_name = first_name_entry.get_text();
        std::string last_name = last_name_entry.get_text();
        combined_name_label.set_text("Names combined: " + first_name + " " + last_name);
    }

    Gtk::Box vbox{Gtk::ORIENTATION_VERTICAL};
    Gtk::Label first_name_label;
    Gtk::Entry first_name_entry;
    Gtk::Label last_name_label;
    Gtk::Entry last_name_entry;
    Gtk::Button combine_button;
    Gtk::Label combined_name_label;
};

int main(int argc, char* argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    NameCombinerWindow window;

    return app->run(window);
}
