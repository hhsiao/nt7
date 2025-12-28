//ken 1999.12.11
inherit ITEM;
void create()
{
        set_name("縷金香爐", ({ "香爐", "縷金香爐"}) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
        /*if( clonep() )
                set_default_object(__FILE__);
        else*/ {
                set("unit", "個");
                set("long", "一個縷金的香爐。似乎有左(left)右(right)轉動過的痕跡。\n");
                set("value", 1);
        }
}

int is_container() { return 1; }
