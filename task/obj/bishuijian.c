#include <ansi.h> 
inherit TASK; 
void create() 
{ 
        set_name( HIG "碧水劍" NOR, ({ "bishui sword" }) ); 
        set_weight(1); 
        if( clonep() ) 
                destruct(this_object()); 
        else { 
                set("unit", "把"); 
                set("material", "iron"); 
                set("long", "這是一把碧水劍。\n"); 
        } 
        set("owner", "嶽靈珊"); 
        setup(); 
} 
