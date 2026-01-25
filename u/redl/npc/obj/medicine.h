// medicine.h

inherit COMBINED_ITEM;

string query_autoload() { return query_amount() + ""; }

varargs void autoload(string param, object owner)
{
        int amt;

        if (sscanf(param, "%d", amt) == 1)
                set_amount(amt);
}

void setup()
{
        set_amount(1);
        ::setup();
}
