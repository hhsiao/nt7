// This program is a part of NT MudLIB
// moduled.c
// 修改支持同時穿多個套裝 by lonely

/*
// 自造裝備套裝數據格式
<1>
<mod_name>$HIC$大道$NOR$</mod_name>
<bas>5</bas>
<num>12</num>
<bas_prop>
add_busy:5
add_weak:5
reduce_busy:5
avoid_weak:5
</bas_prop>
<adv_prop>
avoid_locked:5
add_damage:20
add_skill:50
avoid_busy:5
counter_damage:20
add_locked:5
reduce_damage:5
</adv_prop>
</1>

// 非自造裝備套裝格式...
<M3000>
<mod_name>$CYNGRN$龍之神力$NOR$</mod_name>
<mod_parts>
A3000:$CYNGRN$龍之護腕$NOR$
A3001:$CYNGRN$龍神鱗甲$NOR$
A3002:$CYNGRN$龍神披風$NOR$
A3003:$CYNGRN$龍之束帶$NOR$
A3004:$CYNGRN$惡龍之觸$NOR$
A3005:$CYNGRN$龍骨脛甲$NOR$
A3006:$CYNGRN$龍骨戰衣$NOR$
</mod_parts>
<bas>3</bas>
<num>6</num>
<bas_prop>
avoid_locked:20
add_locked:20
add_busy:10
</bas_prop>
<adv_prop>
reduce_busy:20
avoid_busy:20
add_weak:10
avoid_weak:20
add_damage:20
reduce_damage:20
</adv_prop>
</M3000>

// 非自造套裝部件格式...
<A3002>
<type>armor/surcoat</type>
<name>$CYNGRN$龍神披風$NOR$</name>
<id>dragon surcoat</id>
<value>10000</value>
<mod_level>M3000</mod_level>
<mod_name>$CYNGRN$龍之神力$NOR$</mod_name>
<require>
level:20
con:30
</require>
<quality_level>2</quality_level>
<armor_prop>
armor:10
</armor_prop>
<enchase>
apply_prop/armor1:10
apply_prop/str:2
apply_prop/dex:1
apply_prop/dodge:1
flute:2
used:2
</enchase>
<insert>
[1]
id:magic stone
name:玄石
apply_prop/armor1:10
apply_prop/str:2
[/1]
[2]
id:magic stone
name:靈石
apply_prop/dex:1
apply_prop/dodge:1
[/2]
</insert>
</A3002>
*/

#include <ansi.h>
inherit F_DBASE;

#define EQUIP_LIST      CONFIG_DIR "equiplist/"
#define NCH_CHANNEL(x) CHANNEL_D->channel_broadcast("nch", "套裝精靈："+(string)x)

class eqmodule
{
        string mod_level;       // 套裝序號 作為序引讀取資料
        string mod_name;        // 套裝名稱
        mapping mod_parts;      // 套裝組件名稱
        int bas;                // 套裝激活基本屬性數量
        int num;                // 套裝組件數量
        mapping bas_prop;       // 套裝組合基本屬性
        mapping adv_prop;       // 套裝組合高級屬性
        //mapping add_prop;       // 套裝組合補充屬性，套裝屬性應該是bas_prop+adv_prop+add_prop
}

class eqmodule load_module(string modlevel);
nosave mixed all = ([]);
string module_stats(object obj, object owner);
int valid_module(class eqmodule mod_stats);
void equip_module(object ob, object owner);
void unequip_module(object ob, object owner);

void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "套裝精靈");
        CHANNEL_D->do_channel(this_object(), "sys", "套裝系統已經啟動。");
}

// 根據套裝部件和持有部件者打印部件信息,應用於look.c調用
string module_stats(object ob, object owner)
{
        class eqmodule mod_stats;
        string modlevel, modname, *apply, *eq_files, *key;
        mapping modparts, data;
        mapping stats;
        int i, j, n, bas, num, len = 0;
        string msg, str, eq_str;

        // 初始化資料
        msg = "";
        modlevel = query("mod_level", ob);
        modname = query("mod_name", ob);

        if( classp(query_temp("module/"+modlevel+"_"+modname, owner)) )
        {
                mod_stats = query_temp("module/"+modlevel+"_"+modname, owner);
        }
        else
        {
                if( undefinedp(all[modlevel]) )
                        mod_stats = load_module(modlevel);
                else
                        mod_stats = copy(all[modlevel]);
        }

        // 檢查合法性
        if( valid_module(mod_stats) )
        {
                num = mod_stats->num;   // 套裝部件數量
                // 激活的自造套裝部件或掉落的套裝部件
                if( query_temp("module/"+modlevel+"_"+modname, owner) || !ob->is_item_make() )
                        modparts = mod_stats->mod_parts;

                // 自造未激活套裝部件
                else
                        modparts = query_temp("module/modparts_" + modlevel+"_"+modname, owner);

                if( !mapp(modparts) ) modparts = ([]);
                apply = keys(modparts);

                msg = sprintf(HIW"  %s(%d/%d"NOR")\n",
                               modname,
                               query_temp("module/modamount_"+modlevel+"_"+modname, owner), num);
                msg+= sprintf(NOR "┏--------------------┓\n");

                data = query_temp("module/modparts_" + modlevel+"_"+modname, owner);
                if( !mapp(data) ) data = ([]);
                eq_files = keys(data);

                for( i=0;i<sizeof(apply);i++ )
                {
                        eq_str = "  ";

                        if( member_array(apply[i], eq_files) != -1 )
                                eq_str = WHT "√" NOR;

                        if( query("mod_mark", ob) == apply[i] )
                                if( query_temp("mod_equip", ob) )
                                        eq_str = HIR"√"NOR;
                                else
                                        eq_str = RED"×"NOR;

                        str = sprintf(NOR "┃%s%-18s"NOR"┃\n",eq_str, modparts[apply[i]]);
                        msg += str;
                }
                if( ob->is_item_make() && member_array(query("mod_mark", ob), apply) == -1 )
                {
                        eq_str = RED"×"NOR;
                        str = sprintf(NOR "┃%s%-18s"NOR"┃\n",eq_str, ob->name(1));
                        msg += str;
                }

                msg += sprintf(NOR "┗--------------------┛\n");
                bas = mod_stats->bas;
                if( query_temp("module/modamount_"+modlevel+"_"+modname, owner) >= bas )
                        eq_str = HIR;
                else
                        eq_str = HIK;
                //msg += sprintf(HIG"  裝備效果"NOR")\n");
                msg += sprintf(NOR "%s┏--------------------┓"NOR"\n", eq_str);

                str = sprintf("%d件:", bas);
                msg += sprintf(NOR "%s┃"NOR"%-20s%s┃"NOR"\n", eq_str, str, eq_str);
                stats = copy(mod_stats->bas_prop);
                key = keys(stats);
                if( sizeof(key) > 0 )
                {
                        for( i=0;i<sizeof(key);i++ )
                        {
                                str = EQUIPMENT_D->chinese(key[i], stats[key[i]]);
                                str = HIG + str + NOR;
#ifndef LONELY_IMPROVED
                                len = color_len(str);
#endif
                                msg += sprintf(NOR "%s┃"NOR"%-" + (20 + len) + "s%s┃"NOR"\n",
                                                       eq_str, str, eq_str);
                        }
                }
                if( query_temp("module/modamount_"+modlevel+"_"+modname, owner) == num )
                        eq_str = HIR;
                else
                        eq_str = HIK;
                str = sprintf("%d件:", num);
                msg += sprintf(NOR "%s┃"NOR"%-20s%s┃"NOR"\n", eq_str, str, eq_str);
                stats = copy(mod_stats->adv_prop);
                key = keys(stats);
                if( sizeof(key) > 0 )
                {
                        for( i=0;i<sizeof(key);i++ )
                        {
                                str = EQUIPMENT_D->chinese(key[i], stats[key[i]]);
                                str = HIG + str + NOR;
#ifndef LONELY_IMPROVED
                                len = color_len(str);
#endif
                                msg += sprintf(NOR "%s┃"NOR"%-" + (20 + len) + "s%s┃"NOR"\n",
                                                       eq_str, str, eq_str);
                        }
                }


                msg += sprintf(NOR "%s┗--------------------┛"NOR"\n", eq_str);
        }
        return msg;
}

// 根據檢查一個套裝是否合法，即是否存在，如果套裝數據還是初始化數據，就是不存在。
int valid_module(class eqmodule mod_stats)
{
        if( mod_stats->mod_level == "" )
                return 0;

        if( mod_stats->mod_name == "" )
                return 0;
        /*
        if( !(mod_stats->mod_parts) )
                return 0;

        if( !(mod_stats->bas_prop) )
                return 0;

        if( !(mod_stats->adv_prop) )
                return 0;

        if( !(mod_stats->add_prop) )
                return 0;
        */
        return 1;
}

// 根據序號查找套裝數據
class eqmodule load_module(string modlevel)
{
        string filename, this_file, temp_str;
        object ob;
        class eqmodule item;
        string *field;
        string modname, names, bas_prop, adv_prop;
        int i, bas, num;
        mapping stats;
        string key;
        mixed value;

        if( modlevel[0] == 'M' )
        {
                if ( modlevel[1] == '0' && strlen(modlevel) == 5)
                        filename = EQUIP_LIST+"basic.mod";
                else if ( modlevel[1] == '1' && strlen(modlevel) == 5)
                        filename = EQUIP_LIST+"advance.mod";
                else if ( modlevel[1] == '2' && strlen(modlevel) == 5)
                        filename = EQUIP_LIST+"expert.mod";
                else if ( modlevel[1] == '3' && strlen(modlevel) == 5)
                        filename = EQUIP_LIST+"boss.mod";
        }
        else if( modlevel == "1" || modlevel == "2" || modlevel == "3" || modlevel == "4" )
        {
                // 玩家自造裝備套裝化
                filename = EQUIP_LIST + "ultra.mod";
        }

        // 初始化一個空的套裝文件
        item = new(class eqmodule);
        item->mod_level = "";
        item->mod_name = "";
        item->mod_parts = ([]);
        //item->add_prop = ([]); // 裝備部件增加的套裝屬性

        // 文件為空。返回空值。
        if( !stringp(filename) || file_size(filename) < 0 )
                return item;

        this_file = read_file(filename);

        // 根據套裝序號查找序號所在文件表，查找匹配套裝數據
        sscanf( this_file, "%*s<"+modlevel+">%s</"+modlevel+">%*s", temp_str);
        sscanf( temp_str, "%*s<mod_name>%s</mod_name>%*s", modname);
        sscanf( temp_str, "%*s<mod_parts>\n%s\n</mod_parts>%*s", names);
        sscanf( temp_str, "%*s<bas>%d</bas>%*s", bas);
        sscanf( temp_str, "%*s<num>%d</num>%*s", num);
        sscanf( temp_str, "%*s<bas_prop>\n%s\n</bas_prop>%*s", bas_prop);
        sscanf( temp_str, "%*s<adv_prop>\n%s\n</adv_prop>%*s", adv_prop);

        item->mod_level = modlevel;
        item->mod_name = trans_color(modname, 3); // 轉換顏色

        if( bas ) item->bas = bas;
        if( num ) item->num = num;

        // 解析屬性表，填入屬性關鍵字和套裝屬性。
        if (bas_prop != "")
        {
                stats = ([]);
                field = explode(bas_prop, "\n");
                for (i=0;i<sizeof(field);i++)
                {
                        //field[i] = replace_string(field[i], " ", "");
                        if( sscanf( field[i], "%s:%d", key, value ) != 2 )
                            sscanf( field[i], "%s:%s", key, value );
                        // 無需複雜的解析
                        stats[key] = value;
                }
                item->bas_prop = copy(stats);
        }

        if (adv_prop != "")
        {
                stats = ([]);
                field = explode(adv_prop, "\n");
                for (i=0;i<sizeof(field);i++)
                {
                        //field[i] = replace_string(field[i], " ", "");
                        if( sscanf( field[i], "%s:%d", key, value ) != 2 )
                            sscanf( field[i], "%s:%s", key, value );
                        // 無需複雜的解析
                        stats[key] = value;
                }
                item->adv_prop = copy(stats);
        }

        // 解析文件表，填入文件名稱和套裝部件中文名字。
        if( sizeof(names) )
        {
                stats = ([]);
                field = explode(names, "\n");
                for (i=0;i<sizeof(field);i++)
                {
                        //field[i] = replace_string(field[i], " ", "");
                        field[i] = trans_color(field[i], 3); // 轉換顏色
                        sscanf( field[i], "%s:%s", key, value );
                        stats[key] = value;
                }
                item->mod_parts = copy(stats);
        }

        if( !all ) all = ([]);
        all[modlevel] = copy(item);
        return item;
}

// 裝備套裝部件
// ob套裝部件 owner裝備者
void equip_module(object ob, object owner)
{
        class eqmodule mod_stats;
        class eqmodule tmp_stats;
        mapping data, stats, applied_prop;
        mapping modparts;
        string *apply;
        string modname;
        string modlevel, file, name;
        object *inv, *obs;
        int i, n;
        int bas, num;
        int max_qi, max_jing;

        if( ob->is_item_make() )
        {
                // 自造裝備非裝備主人無法激活套裝屬性
                if( ob->item_owner() != query("id", owner) )
                        return;
        }

        modlevel = query("mod_level", ob); // 套裝的序號、等級
        modname = query("mod_name", ob);   // modname 來判斷是否是套裝

        inv = owner->query_equipment_objects(); // 優化效率
        if( ob->is_item_make() )        // 檢查套裝部件
        {
                obs = filter_array(inv,
                        (: query("mod_name", $1) == $(modname) &&
                           query("mod_level", $1) == $(modlevel) &&
                           $1->is_item_make() && $1->item_owner() == $(query("id", owner)) :));
        }
        else
                obs = filter_array(inv,
                        (: query("mod_name", $1) == $(modname) &&
                           query("mod_level", $1) == $(modlevel) && !$1->is_item_make() :));

        n = sizeof(obs); // 裝備的套裝件數

        // 自造的綠化的時候用base_name作為mark，掉落的用部件序號作為mark
        file = query("mod_mark", ob);
        name = query("name", ob);

        // 標記套裝組件
        modparts=query_temp("module/modparts_"+modlevel+"_"+modname, owner);
        if( !mapp(modparts) || !sizeof(modparts) ) modparts = ([]);
        modparts[file] = name;
        set_temp("module/modparts_"+modlevel+"_"+modname, modparts, owner);

        // 標記套裝件數
        addn_temp("module/modamount_"+modlevel+"_"+modname, 1, owner);

        // 裝備的套裝設置標記
        set_temp("mod_equip", 1, ob);

        // 少於2件不成套裝
        if( n < 2 ) return;

        // 讀取套裝資料
        if( undefinedp(all[modlevel]) )
                mod_stats = load_module(modlevel);
        else
                mod_stats = copy(all[modlevel]);

        // 檢查合法性
        //if( !valid_module(mod_stats) )
        //        return;

        bas = mod_stats->bas;
        num = mod_stats->num;

        if( n < bas ) return; // 小於最少激活套裝數量，無法激活套裝屬性
        else if( n == bas )
        {
                // 加上正在裝備的ob，正好激活套裝屬性
                mod_stats->mod_name = modname;
                if( ob->is_item_make() )        // 補充套裝的部件資料
                        mod_stats->mod_parts = ([ file : name ]);

                set_temp("mod_active", 1, ob);  // look時候顏色變化

                for( i=0; i<n; i++ ) {
                        if( ob->is_item_make() ) // 補充自造套裝部件資料
                        {
                                data = copy(mod_stats->mod_parts);
                                data[query("mod_mark", obs[i])] = obs[i]->name(1);
                                mod_stats->mod_parts = copy(data);
                        }

                        set_temp("mod_active", 1, obs[i]);  // look時候顏色變化以及激活綠化屬性
                }

                set_temp("module/"+modlevel+"_"+modname, mod_stats, owner);  // 玩家身上標記套裝屬性
                set_temp("fullsuit/"+modlevel+"_"+modname, mod_stats->bas_prop, owner);
        }
        else if( n == num )
        {
                if( !classp(tmp_stats = copy(query_temp("module/"+modlevel+"_"+modname, owner))) )
                        error("套裝屬性出現混亂，請立刻提交bug給admin。\n");

                // 套裝全齊了
                mod_stats->mod_name = modname;
                if( ob->is_item_make() )
                {
                        data = copy(tmp_stats->mod_parts);
                        data[file] = name;
                        mod_stats->mod_parts = copy(data);
                }

                set_temp("mod_active", 1, ob);

                set_temp("module/"+modlevel+"_"+modname, mod_stats, owner);  // 玩家身上標記套裝屬性


                applied_prop = copy(mod_stats->bas_prop);
                stats = copy(mod_stats->adv_prop);
                apply = keys(stats);
                for( i = 0; i<sizeof(apply); i++ )
                {
                        if( undefinedp(applied_prop[apply[i]]) )
                                applied_prop[apply[i]] = stats[apply[i]];
                        else
                                applied_prop[apply[i]] += stats[apply[i]];
                }

                set_temp("fullsuit/"+modlevel+"_"+modname, applied_prop, owner);

                if( ob->is_item_make() ) // 備齊了全套裝備
                        set_temp("modequip_itemmake_level", to_int(modlevel), owner);     // 玩家身上標記全套的自造套裝等級
        }
        else
        {
                // 已經激活套裝屬性，附加新的套裝單件屬性
                // 首先檢查已經激活的套裝屬性是否出了問題
                if( !classp(tmp_stats = copy(query_temp("module/"+modlevel+"_"+modname, owner))) )
                        error("套裝屬性出現混亂，請立刻提交bug給admin。\n");

                mod_stats->mod_name = modname;

                if( ob->is_item_make() )
                {
                        data = copy(tmp_stats->mod_parts);
                        data[file] = name;
                        mod_stats->mod_parts = copy(data);
                }

                set_temp("mod_active", 1, ob);

                set_temp("module/"+modlevel+"_"+modname, mod_stats, owner);  // 玩家身上標記套裝屬性
                set_temp("fullsuit/"+modlevel+"_"+modname, mod_stats->bas_prop, owner);
        }

        // 戰場上無效
        if( query_temp("warquest", owner) ) return;

        owner->reset_buff_cache();

        max_qi = query("max_qi", owner);
        max_jing = query("max_jing", owner);
        CHAR_D->setup_char(owner);
        if( query("eff_qi", owner) >= max_qi )
                max_qi = query("max_qi", owner) - max_qi;
        else
                max_qi = 0;
        if( query("eff_jing", owner) >= max_jing )
                max_jing = query("max_jing", owner) - max_jing;
        else
                max_jing = 0;
        addn("eff_qi", max_qi, owner);
        addn("eff_jing", max_jing, owner);

        return;
}

// 卸下套裝部件
// ob套裝部件 owner裝備者
void unequip_module(object ob, object owner)
{
        class eqmodule mod_stats;
        class eqmodule tmp_stats;
        mapping data, stats, prop, applied_prop;
        mapping modparts;
        string *apply;
        string modname;
        string modlevel, file, name;
        object *inv, *obs;
        int i, j, n, flag = 0;
        int bas, num;

        if( ob->is_item_make() ) {
                if( ob->item_owner() != query("id", owner) )
                        return;
        }

        modlevel = query("mod_level", ob);
        modname = query("mod_name", ob);

        inv = owner->query_equipment_objects();
        if( ob->is_item_make() )        // 檢查套裝部件
        {
                obs = filter_array(inv,
                        (: query("mod_name", $1) == $(modname) &&
                           query("mod_level", $1) == $(modlevel) &&
                           $1->is_item_make() && $1->item_owner() == $(query("id", owner)) :));
        }
        else
                obs = filter_array(inv,
                        (: query("mod_name", $1) == $(modname) &&
                           query("mod_level", $1) == $(modlevel) && !$1->is_item_make() :));

        n = sizeof(obs);

        // 檢查套裝部件ob是否是套裝裡的一件
        file = query("mod_mark", ob);
        name = query("name", ob);

        // 標記套裝文件
        modparts=query_temp("module/modparts_"+modlevel+"_"+modname, owner);
        if( !mapp(modparts) || !sizeof(modparts) )
                modparts = ([]);

        map_delete(modparts, file);
        set_temp("module/modparts_"+modlevel+"_"+modname, modparts, owner);


        // 標記套裝件數
        addn_temp("module/modamount_"+modlevel+"_"+modname, -1, owner);
        if( query_temp("module/modamount_"+modlevel+"_"+modname, owner)<=0 )
                delete_temp("module/modamount_"+modlevel+"_"+modname, owner);

        // 刪除裝備套裝部件標記
        delete_temp("mod_equip", ob);
        delete_temp("mod_active", ob); // look時候顯示mod_prop顏色變化

        /*
        if( query_temp("module/modamount_"+modlevel+"_"+modname, owner) != n )
                error("套裝裝備件數出現混亂，請立刻提交bug給admin。\n");
        */

        // 少於2件不成套裝
        if( n < 1 ) return;


        // 讀取套裝資料
        if( undefinedp(all[modlevel]) )
                mod_stats = load_module(modlevel);
        else
                mod_stats = copy(all[modlevel]);

        // 檢查合法性
        //if( !valid_module(mod_stats) )
        //        return;

        bas = mod_stats->bas;
        num = mod_stats->num;

        // 如果onwer身上裝備的套裝件數+1未達到套裝激活件數時，
        // 因為沒附加過套裝屬性，所以不需要執行刪除onwer套裝屬性
        if( n < bas-1 ) return;
        else if( n == bas-1 ) {
                if( !classp(tmp_stats = copy(query_temp("module/"+modlevel+"_"+modname, owner))) )
                        error("套裝屬性出現混亂，請立刻提交bug給admin。\n");

                // 正好bas件，卸下套裝部件，則消除套裝的所有補充屬性和基本屬性
                for( i=0; i<sizeof(obs); i++ )
                {
                        if( obs[i] == ob ) continue;
                        delete_temp("mod_equip", obs[i]);   // 取消裝備標記
                        delete_temp("mod_active", obs[i]);  // 取消激活標記
                }

                delete_temp("module/"+modlevel+"_"+modname, owner);
                delete_temp("fullsuit/"+modlevel+"_"+modname, owner);

                return;
        }
        else if( n == num-1 ) {
                if( !classp(tmp_stats = copy(query_temp("module/"+modlevel+"_"+modname, owner))) )
                        error("套裝屬性出現混亂，請立刻提交bug給admin。\n");

                mod_stats->mod_name = modname;
                if( ob->is_item_make() )
                {
                        data = copy(tmp_stats->mod_parts);
                        map_delete(data, file);
                        mod_stats->mod_parts = copy(data);
                }

                set_temp("module/"+modlevel+"_"+modname, mod_stats, owner);
                set_temp("fullsuit/"+modlevel+"_"+modname, mod_stats->bas_prop, owner);

                if( ob->is_item_make() )
                        delete_temp("modequip_itemmake_level", owner); // 刪除套裝等級，suit special調用

                return;
        }
        else
        {
                if( !classp(tmp_stats = copy(query_temp("module/"+modlevel+"_"+modname, owner))) )
                        error("套裝屬性出現混亂，請立刻提交bug給admin。\n");

                mod_stats->mod_name = modname;  // 自造套裝名稱不是一樣
                if( ob->is_item_make() )
                {
                        data = copy(tmp_stats->mod_parts);
                        map_delete(data, file);
                        mod_stats->mod_parts = copy(data);
                }

                set_temp("module/"+modlevel+"_"+modname, mod_stats, owner);
                set_temp("fullsuit/"+modlevel+"_"+modname, mod_stats->bas_prop, owner);

                return;
        }
}

// 調用來自 /cmds/std/suit.c 使用套裝特技
public int suit_special(object me, string arg)
{
        mapping buff, data;
        string msg;
        mapping map_status;
        string *mname;
        object *obs;
        int i, suitlvl, skill, temp;

        suitlvl = query_temp("modequip_itemmake_level", me);

        /*
        並額外附加套裝特技 星辰之力(stars)。施展(special stars <項目>)
        後可提升下列某項狀態 50% ，並持續 10 分鐘。
        無視攻擊、無視躲閃、無視招架、無視內功、抗毒效果、毒素傷害
        虛弱對手、解封絕招、絕招傷害、絕招命中、雙倍傷害、
        化解傷害、抵抗虛弱、封存絕招、絕招防禦、研究效果、汲取效果
        */

        obs = me->query_equipment_objects();
        obs = filter_array(obs,
                        (: $1->is_item_make() /*&& $1->item_owner() == $(query("id", me))*/ :));

        if( sizeof(obs) < 9 )
                return notify_fail("你沒有裝備全套的九件裝備。\n");

        if( suitlvl < 4 )
                return notify_fail("你目前裝備的套裝等級不夠，無法使用套裝特技！\n");

        for( i=0; i<sizeof(obs); i++ )
        {
                if( query("qianghua/level", obs[i]) < 9 )
                        return notify_fail("由於"+obs[i]->name(1)+NOR"不是九星裝備，無法使用套裝特技！\n");
        }

        if( arg == "sun" ) // 增加命中
        {

                if( BUFF_D->check_buff(me, "powerofsun") )
                        return notify_fail("你現在正在運用此類特技中，請稍後再使用。\n");

                if( query("neili", me) < 1000000 )
                        return notify_fail("你的內力不足，無法施展套裝絕技。\n");

                if( query("neili", me) < query("max_neili", me) )
                        return notify_fail("你的剩餘內力不足，無法施展套裝絕技。\n");

                if( query("neili", me) > 2 * query("max_neili", me) ) set("neili", 2 * query("max_neili", me), me);
                skill = query("neili", me) / 10000;
                set("neili", 0, me);

                msg = HIC "$N" HIC "一聲長吟，只見太陽之力源源不盡被吸進全身裝備，剎那間流光異彩，將其籠罩！\n" NOR;

                data = ([]);
                map_status = me->query_skill_map();
                if( sizeof(map_status) )
                {
                        mname  = keys(map_status);
                        temp = sizeof(map_status);

                        for( i=0; i<temp; i++ )
                                data[mname[i]] = skill;
                }

                data +=
                ([
                        "str"   : skill,
                        "int"   : skill,
                        "attack": skill,
                        "ap_power": 200,
                ]);

                buff =
                ([
                        "caster": me,
                        "target": me,
                        "type"  : "atkup",
                        "type2" : "powerofsun",
                        "attr"  : "bless",
                        "name"  : "套裝特技·太陽之力",
                        "time"  : skill,
                        "buff_data": data,
                        "buff_msg" : msg,
                        "disa_msg" : "你的套裝特技·太陽之力運行完畢，將內力收回丹田。\n",
                ]);

                BUFF_D->buffup(buff);

                return 1;
        }

        else if( arg == "moon" )  // 增加傷害
        {
                if( BUFF_D->check_buff(me, "powerofmoon") )
                        return notify_fail("你現在正在運用此類特技中，請稍後再使用。\n");

                if( query("neili", me) < 1000000 )
                        return notify_fail("你的內力不足，無法施展套裝絕技。\n");

                if( query("neili", me) < query("max_neili", me) )
                        return notify_fail("你的剩餘內力不足，無法施展套裝絕技。\n");

                if( query("neili", me) > 2 * query("max_neili", me) ) set("neili", 2 * query("max_neili", me), me);
                skill = query("neili", me) / 10000;
                set("neili", 0, me);

                msg = HIR "$N舉頭望天，悠然一聲長嘆，剎那間月亮之力源源不盡被吸進全身裝備，全身被紅色的光芒包裹，殺氣驟現！\n" NOR;

                data = ([]);
                map_status = me->query_skill_map();
                if( sizeof(map_status) )
                {
                        mname  = keys(map_status);
                        temp = sizeof(map_status);

                        for( i=0; i<temp; i++ )
                                data[mname[i]] = skill;
                }

                data +=
                ([
                        "str"   : skill,
                        "damage"   : skill,
                        "unarmed_damage": skill,
                        "da_power": 300,
                ]);

                buff =
                ([
                        "caster": me,
                        "target": me,
                        "type"  : "damageup",
                        "type2" : "powerofmoon",
                        "attr"  : "bless",
                        "name"  : "套裝特技·月亮之力",
                        "time"  : skill,
                        "buff_data": data,
                        "buff_msg" : msg,
                        "disa_msg" : "你的套裝特技·月亮之力運行完畢，將內力收回丹田。\n",
                ]);

                BUFF_D->buffup(buff);

                return 1;
        }

        else if( arg == "star" )
        {
                if( BUFF_D->check_buff(me, "powerofstar") )
                        return notify_fail("你現在正在運用此類特技中，請稍後再使用。\n");

                if( query("neili", me) < 1000000 )
                        return notify_fail("你的內力不足，無法施展套裝絕技。\n");

                if( query("neili", me) < query("max_neili", me) )
                        return notify_fail("你的剩餘內力不足，無法施展套裝絕技。\n");

                if( query("neili", me) > 2 * query("max_neili", me) ) set("neili", 2 * query("max_neili", me), me);
                skill = query("neili", me) / 10000;
                set("neili", 0, me);

                msg = HIR "$N長嘯一聲，頓時星辰之力源源不盡被吸進全身裝備，所過之處泛出紅色血芒，令人心膽具寒。\n" NOR;

                data =
                ([
                        "leech_neili" : 30,
                        "leech_qi"    : 30,
                        "qi_abs_neili": 30,
                        "fatal_blow"  : 30,
                        "avoid_busy"  : 30,
                ]);

                buff =
                ([
                        "caster": me,
                        "target": me,
                        "type"  : "powerup",
                        "type2" : "powerofstar",
                        "attr"  : "bless",
                        "name"  : "套裝特技·星辰之力",
                        "time"  : skill,
                        "buff_data": data,
                        "buff_msg" : msg,
                        "disa_msg" : "你的套裝特技·星辰之力運行完畢，將內力收回丹田。\n",
                ]);

                BUFF_D->buffup(buff);

                return 1;
        }

        else
                write("套裝特技使用格式：suit sun|moon|star\n");

        return 1;
}
