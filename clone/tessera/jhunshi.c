#include <ansi.h>
inherit ITEM;

int is_can_merge() { return 1; }
void create()
{
        set_name(HIR "精魂石碎片" NOR, ({"jinghun shi", "jinghun", "shi"}));
        set_weight(30);

        set("long", HIR "稀有度較高的裝備分解後所得到的核心碎片，擁有著神奇的力量。\n" NOR);
        set("unit", "塊");
        set("value", 12000);
        set("auto_load", 1);
        
        setup();
}

string extra_long()
{
        mapping data;
        string *apply, str;
        string type;
        mixed value;
        int i;

        str = "";
        type = query("enchase/type"); 
        if( type )
                str += sprintf(WHT "裝備材料 : %s(%s)\n" NOR, to_chinese(type), type); 

        if( mapp(data = copy(query("enchase/apply_prop"))) ) 
        {
                apply = keys(data);
                for (i = 0; i<sizeof(apply); i++) { 
                        value = data[apply[i]]; 
                        str += HBCYN "擁有屬性" NOR " : "; 
                        str += EQUIPMENT_D->chinese(apply[i], value) + "\n"; 
                }
        }
        return str;
}