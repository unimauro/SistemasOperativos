#crito por Daniel Fuentes B.
# Licencia: BSD <http://www.opensource.org/licenses/bsd-license.php>
 
import pygtk
pygtk.require("2.0")
import gtk
import webkit
 
class Browser:
    # Ventana del programa
    def __init__(self):
        self.window = gtk.Window(gtk.WINDOW_TOPLEVEL)
        self.window.set_position(gtk.WIN_POS_CENTER)
        self.window.set_default_size(800, 600)
        self.window.connect("destroy", self.on_quit)
 
        # Un vBox, en la parte de arriba hay una caja para ingresar
        # la direccion web, y abago se muestra la pagina
        vbox = gtk.VBox()
 
        # La parte de la entrada de la url
        self.url_text = gtk.Entry()
        self.url_text.connect('activate', self.url_text_activate)
 
        # La parte en donde se muestra la pagina que se visita (con scroll incluido)
        self.scroll_window = gtk.ScrolledWindow()
        self.webview = webkit.WebView()
        self.scroll_window.add(self.webview)
 
        # Unimos todo en el vBox
        vbox.pack_start(self.url_text, fill=True, expand=False)
        # El expand=False al empaquetarlo es para que el entry no ocupe media pantalla
        vbox.pack_start(self.scroll_window, True, True)
        self.window.add(vbox)
        self.window.show_all()
 
    # Definimos las senales y demas cosas de la ventana:
    def url_text_activate(self, entry):
    # al activar el entry (por ejemplo al hacer enter), se obtiene el
    # texto de la entry (la url) y se activa la funcion que abre la url
        self.open_url(entry.get_text())
 
    def on_quit(self, widget):
        gtk.main_quit()
 
    # La funcion magica que abre la url que se le pasa 
    def open_url(self, url):
        "Funcion que carga la pagina elegida"
        # cambia el titulo de la ventana
        self.window.set_title("Ejemplo pywebkitgtk - %s" % url)
        # mostramos la direccion de la pagina abierta en el entry
        self.url_text.set_text(url)
        # abre la pagina
        self.webview.open(url)
 
if __name__ == "__main__":
    browser = Browser()
    # abrimos la pagina de inicio (opcional)
    browser.open_url("http://127.0.0.1:9000") 
    gtk.main()
