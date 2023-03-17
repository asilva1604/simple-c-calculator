#include <gtk/gtk.h>


static void zeroFun(GtkWidget *widget, gpointer data) {
  g_print("You pressed zero\n");
}

static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
  g_print ("This is my first application\n");
}

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  
  //declaration of each widget (in this case, buttons)
  GtkWidget *window;
  GtkWidget *grid_numbers;
  GtkWidget *zero;
  GtkWidget *one;
  GtkWidget *comma;
  GtkWidget *mod;
  GtkWidget *plus;
  GtkWidget *equal;
  GtkWidget *squared;
  GtkWidget *minus;
  GtkWidget *mult;
  GtkWidget *sqrt;
  GtkWidget *divide;
  GtkWidget *two;
  GtkWidget *three;
  GtkWidget *four;
  GtkWidget *five;
  GtkWidget *six;
  GtkWidget *seven;
  GtkWidget *eight;
  GtkWidget *nine;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "The C Calculator");
  gtk_window_set_default_size (GTK_WINDOW (window), 300, 490);

  grid_numbers = gtk_grid_new();
  gtk_widget_set_halign(grid_numbers, GTK_ALIGN_CENTER);
  gtk_widget_set_valign(grid_numbers, GTK_ALIGN_END);
  gtk_grid_set_row_homogeneous(GTK_GRID(grid_numbers), true);
  gtk_grid_set_column_homogeneous(GTK_GRID(grid_numbers), true);
  //gtk_grid_set_column_spacing(GTK_GRID(grid_numbers), 100);
  //gtk_grid_set_row_spacing(GTK_GRID(grid_numbers), 100);

  gtk_window_set_child(GTK_WINDOW(window), grid_numbers);

  zero = gtk_button_new_with_label("0");
  //implement logic
  gtk_grid_attach(GTK_GRID(grid_numbers), zero, 0, 0, 10, 10);
  g_signal_connect(zero, "clicked", G_CALLBACK(zeroFun), NULL);

  comma = gtk_button_new_with_label(",");
  gtk_grid_attach_next_to(GTK_GRID(grid_numbers), comma, zero, GTK_POS_RIGHT,10, 10);
  
  mod = gtk_button_new_with_label("%");
  gtk_grid_attach_next_to(GTK_GRID(grid_numbers), mod, comma, GTK_POS_RIGHT, 10, 10);

  plus = gtk_button_new_with_label("+");
  gtk_grid_attach_next_to(GTK_GRID(grid_numbers), plus, mod, GTK_POS_RIGHT, 10, 10);
  
  equal = gtk_button_new_with_label("=");
  gtk_grid_attach_next_to(GTK_GRID(grid_numbers), equal, plus, GTK_POS_RIGHT, 10, 20);

  one = gtk_button_new_with_label("1");
  gtk_grid_attach_next_to(GTK_GRID(grid_numbers), one, zero, GTK_POS_TOP, 10, 10);


  gtk_window_present (GTK_WINDOW (window));
}

int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_REPLACE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
