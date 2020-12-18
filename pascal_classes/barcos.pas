program borrame;

const
    MaxFilas = 10;
    MaxCols = 10;
    MaxBarcos = 3;  {Barcos por jugada}
    MinCol = 'A';
    MaxCol = 'J';
    MinFila = 1;
    LongSub = 1;
    LongFrag = 2;
    LongDrag = 3;

{Tipos de Datos:}

type
    TipoComando = (Jugador, Fin);
    TipoFila = 1..MaxFilas;
    TipoColumna = MinCol..MaxCol;

    TipoClaseBarco = (Fragata, Submarino, Dragaminas);
    TipoOrientacion = (Horizontal, Vertical);
    TipoCasilla = record
        fila: TipoFila;
        col: TipoColumna;
    end;

    TipoBarco = record
        clase: TipoClaseBarco;
        ori: TipoOrientacion;
        casilla: TipoCasilla;
    end;

    TipoJugada = array[0..Maxbarcos - 1] of TipoBarco;

function columna(pos: integer): char;
{
    Devuelve la columna (como char, a partir de 'A')
    asociada al indice 'pos'
}
begin
    columna := chr(ord(MinCol) + pos);
end;

function index_columna(col: char): integer;
begin
    index_columna := ord(col) - ord(MinCol);
end;

function casillas_iguales(c1, c2: TipoCasilla): boolean;
begin
    casillas_iguales := (c1.fila = c2.fila) and (c1.col = c2.col);
end;

function long_barco(clase_barco: TipoClaseBarco): integer;
var
    l: integer;
begin
    case clase_barco of
        Fragata:
            l := LongFrag;
        Submarino:
            l := LongSub;
        Dragaminas:
            l := LongDrag;
    end;

    long_barco := l;
end;

function casilla_ok(cas: TipoCasilla): boolean;
begin
    casilla_ok := (cas.fila >= MinFila) and (cas.fila <= MaxFilas) and
        (ord(cas.col) >= ord(MinCol)) and (ord(cas.col) <= ord(MaxCol));
end;

function inicial_barco(clase_barco: TipoClaseBarco): char;
var
    c: char;
begin
    case clase_barco of
        Fragata:
            c := 'F';
        Submarino:
            c := 'S';
    else
        c := 'D';
    end;

    inicial_barco := c;
end;

procedure actualizar_casilla(b: TipoBarco; desp: integer; var c: TipoCasilla);
{
    'desp': Desplazamiento con respecto a la casilla donde se encuentra la
            proa del barco
}
var
    ind: integer;
begin
    if (b.ori = Horizontal) then
            begin
                ind := index_columna(b.casilla.col) + desp;
                {Actualizar casilla}
                c.fila := b.casilla.fila;
                c.col := columna(ind);
            end
            else
            begin
                ind := b.casilla.fila + desp;
                {Actualizar casilla}
                c.col := b.casilla.col;
                c.fila := ind;
            end;
end;

function casilla_ocupada(jug: TipoJugada; casilla: TipoCasilla;
    var inicial: char): boolean;
var
    i, j, long: integer;
    ret: boolean;
    cas: TipoCasilla;
begin
    i := 0;
    ret := False;
    while (i < MaxBarcos) and (not ret) do
    begin
        long := long_barco(jug[i].clase);

        for j := 0 to long - 1 do
        begin
            actualizar_casilla(jug[i], j, cas);

            if (casilla_ok(cas)) then
            begin
                if (casillas_iguales(cas, casilla)) then
                begin
                    ret := True;
                    inicial := inicial_barco(jug[i].clase);
                end;
            end;
        end;
        i := i + 1;
    end;

    casilla_ocupada := ret;
end;

procedure leer_barco(var b: TipoBarco);
begin
    readln(b.clase);
    readln(b.casilla.col);
    readln(b.casilla.fila);
    readln(b.ori);
end;

procedure impr_cabecera_tablero();
var
    i: integer;
begin
    for i := 0 to MaxCols - 1 do
    begin
        write(columna(i));
        write(' ');
    end;
    writeln('');
end;

procedure impr_tablero(jug: TipoJugada);
var
    i, j: integer;
    inicial: char;
    cas: TipoCasilla;
begin
    impr_cabecera_tablero();

    for i := MinFila to MaxFilas do
    begin
        for j := 0 to MaxCols - 1 do
            begin
            cas.fila := i;
            cas.col := columna(j);
            if (casilla_ocupada(jug, cas, inicial)) then
            begin
                write(inicial);
                write(' ');
            end
            else
            begin
                write('. ');
            end;
        end;
        writeln(i);
    end;
end;

procedure leer_jugada(var j: TipoJugada);
var
    i: integer;
    b: TipoBarco;
begin
    for i := 0 to MaxBarcos - 1 do
    begin
        leer_barco(b);
        j[i] := b;
    end;
end;

var
    comando: TipoComando;
    jugada: TipoJugada;

begin
    repeat
        readln(comando);
        if (comando <> fin) then
        begin
            leer_jugada(jugada);
            impr_tablero(jugada);
        end;
    until (comando = Fin);
end.