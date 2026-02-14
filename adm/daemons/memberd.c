// This program is a part of NITAN MudLIB
// memberd.c 會員精靈

// #pragma optimize
// #pragma save_binary

#ifdef DB_SAVE

#include <ansi.h>
#include <mudlib.h>
#include "/adm/etc/database.h"
#define GOODS_D         "/adm/daemons/goodsd"
#define VERSION         "V 2.0"

public int is_member(mixed ob);
public int is_valid_member(mixed ob);
public mixed db_query_member(mixed ob, mixed key);
public mixed db_find_member(string key, mixed data);
public varargs int db_create_member(mixed ob, int money, string from_id);
public int db_remove_member(mixed ob);
public int db_bulk_update_member(mixed ob, mapping data);
public int db_set_member(mixed ob, string key, mixed data);
public int db_add_member(mixed ob, string key, int num);
public varargs int db_pay_member(mixed ob, int money, string from_id);
public int db_transfer_member(mixed ob, mixed to, int value);

int clean_up(int inherited) { return 1; }

protected int valid_caller() {
#ifdef DEBUG
    return 1;
#else
    if (!previous_object() ||
        !is_root(previous_object()))
        return 0;
    else
        return 1;
#endif
}

void create() {
    seteuid(ROOT_UID);
}

// 查詢 ID 是否是衝值用戶
public int is_member(mixed ob) {
    mixed ret;
    string id, sql;

    if (objectp(ob))
        id = query("id", ob);
    else
        if (stringp(ob))
        id = ob;
    else
        return 0;

    sql = sprintf("SELECT id FROM %s WHERE id = %s",
        MEMBER_TABLE, DB_STR(id));

    ret = DATABASE_D->db_query(sql);

    return ret;
}

// 查詢 ID 是否是有效會員
public int is_valid_member(mixed ob) {
    mixed ret;
    string id, sql;

    if (objectp(ob))
        id = query("id", ob);
    else
        if (stringp(ob))
        id = ob;
    else
        return 0;

    sql = sprintf("SELECT id FROM %s WHERE id = %s AND endtime > %d",
        MEMBER_TABLE, DB_STR(id), time());

    ret = DATABASE_D->db_query(sql);

    return ret;
}

// 會員雙倍獎勵時間
public int is_double_reward(object ob) {
    /*
     * t = localtime(time())[2];

     * if (is_valid_member(ob) &&
     * t >= 20 && t < 24)
     * return 1;
     * t = localtime(time())[3];
     * if (t >= 0 && t < 4)
     * return 1;
     */

    if(query("time_reward/quest", ob) )
        return 1;

    return 0;
}

// Helper function to validate column names
private int valid_column_name(string col) {
    int i, len;

    if (!stringp(col) || col == "")
        return 0;

    len = strlen(col);

    // Column names should only contain alphanumeric characters and underscores
    // First character should be a letter or underscore
    for (i = 0; i < len; i++) {
        if (i == 0) {
            // First character: letter or underscore
            if (!((col[i] >= 'a' && col[i] <= 'z') ||
                  (col[i] >= 'A' && col[i] <= 'Z') ||
                  col[i] == '_'))
                return 0;
        }
        else {
            // Subsequent characters: letter, digit, or underscore
            if (!((col[i] >= 'a' && col[i] <= 'z') ||
                  (col[i] >= 'A' && col[i] <= 'Z') ||
                  (col[i] >= '0' && col[i] <= '9') ||
                  col[i] == '_'))
                return 0;
        }
    }

    // Check for SQL keywords that could be dangerous
    col = lower_case(col);
    if (col == "select" || col == "from" || col == "where" ||
        col == "insert" || col == "update" || col == "delete" ||
        col == "drop" || col == "union" || col == "exec" ||
        col == "execute" || col == "alter" || col == "create")
        return 0;

    return 1;
}

// 查詢 ID 相關信息
// 查詢 ID 相關信息
public mixed db_query_member(mixed ob, mixed key) {
    mixed ret;
    string id, sql, *columns;
    int i, single_column;
    // Define which columns are integers in the database (mapping for O(1) lookup)
    mapping int_columns = ([
        "money": 1, "vip": 1, "jointime": 1, "endtime": 1,
        "paytimes": 1, "payvalue": 1, "buytimes": 1, "buyvalue": 1,
        "transfertimes": 1, "transfervalue": 1, "last_paytime": 1,
        "last_buytime": 1, "last_payvalue": 1, "last_buyvalue": 1
    ]);

    if (objectp(ob))
        id = query("id", ob);
    else if (stringp(ob))
        id = ob;
    else
        return 0;

    if (!stringp(id) || id == "")
        return 0;

    // Handle string, comma-separated string, or array for key parameter
    if (stringp(key)) {
        if (key == "")
            return 0;

        // Check if it contains a comma (multiple columns)
        if (strsrch(key, ",") != -1) {
            // Split by comma and trim whitespace
            columns = explode(key, ",");
            columns = map(columns, (: trim($1) :));
            single_column = 0;
        }
        else {
            // Single column
            columns = ({ trim(key) });
            single_column = 1;
        }
    }
    else if (arrayp(key)) {
        if (!sizeof(key))
            return 0;
        columns = key;
        single_column = 0;
    }
    else
        return 0;

    // Validate column names to prevent SQL injection
    for (i = 0; i < sizeof(columns); i++) {
        if (!valid_column_name(columns[i]))
            return 0;
    }

    // Build column list for SQL query
    sql = sprintf("SELECT %s FROM %s WHERE id = %s",
        implode(columns, ", "), MEMBER_TABLE, DB_STR(id));

    ret = DATABASE_D->db_fetch_row(sql);

    if (!arrayp(ret) || !sizeof(ret))
        return 0;

    // Cast integer columns to int (O(1) lookup per column)
    for (i = 0; i < sizeof(ret); i++) {
        if (int_columns[columns[i]]) {  // O(1) lookup instead of O(n)
            ret[i] = to_int(ret[i]);
        }
    }

    // Return single value for single column query
    if (single_column)
        return ret[0];

    // Return mapping for multiple columns
    return allocate_mapping(columns, ret);
}

// 根據條件尋找會員
public mixed db_find_member(string key, mixed data) {
    mixed ret;
    string sql;

    if (!stringp(key) || key == "" || !data)
        return 0;

    if (intp(data))
        sql = sprintf("SELECT id FROM %s WHERE %s = %d",
            MEMBER_TABLE, key, data);
    else if (mapp(data) || arrayp(data))
        sql = sprintf("SELECT id FROM %s WHERE %s = %s",
            MEMBER_TABLE, key, DB_STR(save_variable(data)));
    else if (stringp(data))
        sql = sprintf("SELECT id FROM %s WHERE %s = %s",
            MEMBER_TABLE, key, DB_STR(data));
    else
        sql = sprintf("SELECT id FROM %s WHERE %s = %O",
            MEMBER_TABLE, key, data);

    ret = DATABASE_D->db_all_query(sql);

    return ret;
}

// 創建新的會員
public varargs int db_create_member(mixed ob, int money, string from_id)
{
    mixed ret;
    string id, sql;
    string payinfo;
    object target;

    if (!valid_caller())
        return 0;

    if (objectp(ob))
        id = query("id", ob);
    else
        if (stringp(ob))
        id = ob;
    else
        return 0;

    if (!stringp(id) || id == "")
        return 0;

    /*
     * if (is_member(id))
     * return 0;
     */

    if (!stringp(from_id) || from_id == "")
        payinfo = sprintf("你於 %s 衝值 %d $NT。\n", TIME_D->replace_ctime(time()), money);
    else
        payinfo = sprintf("你於 %s 收到 %s 的轉帳 %d $NT。\n",
            TIME_D->replace_ctime(time()), from_id, money);

#ifdef USE_POSTGRESQL
    sql = sprintf("INSERT INTO %s (id, uid, money, paytimes, payinfo, payvalue, last_payvalue, last_paytime) \
        VALUES (%s, %s, %d, 1, %s, %d, %d, %d)",
        MEMBER_TABLE, DB_STR(id), DB_STR(id), money,
        DB_STR(payinfo), money, money, time());
#else
    sql = sprintf("INSERT INTO %s SET id = %s, uid = %s, money = %d, paytimes = 1, payinfo = %s,
        payvalue = %d, last_payvalue = %d, last_paytime = %d",
        MEMBER_TABLE, DB_STR(id), DB_STR(id), money, DB_STR(payinfo), money, money, time());
#endif

    ret = DATABASE_D->db_query(sql);
    if (!intp(ret) || ret != 1)  // Should insert exactly 1 row
        return 0;

    if (objectp(target = find_player(id)))
    {
        tell_object(target, "\a", 0);
        tell_object(target, HIR + payinfo + NOR);
    }
    return 1;  // Return success, not row count
}

// 刪除會員
public int db_remove_member(mixed ob) {
    mixed ret;
    string id, sql;

    if (!valid_caller())
        return 0;

    if (objectp(ob))
        id = query("id", ob);
    else
        if (stringp(ob))
        id = ob;
    else
        return 0;

    if (!stringp(id) || id == "")
        return 0;

    sql = sprintf("DELETE FROM %s WHERE id = %s",
        MEMBER_TABLE, DB_STR(id));
    ret = DATABASE_D->db_query(sql);

    if (!intp(ret) || ret != 1)  // Should delete exactly 1 row
        return 0;

    return 1;  // Return success, not row count
}

// Bulk update member data in database
// data format: ([ "field": ({ "operation", value }), ... ])
// operation: "add" or "set"
// Example: ([ "money": ({ "add", 100 }), "vip": ({ "set", 1 }) ])
public int db_bulk_update_member(mixed ob, mapping data) {
    string id, sql;
    string *updates = ({});
    int result;

    // Get player ID
    if (objectp(ob)) {
        id = ob->query_id();
    }
    else if (stringp(ob)) {
        id = ob;
    }
    else {
        return 0;
    }

    if (!id || !mapp(data) || !sizeof(data)) {
        return 0;
    }

    // Build UPDATE clauses
    foreach(string field, mixed value in data) {
        string operation;
        mixed set_value;

        // Validate format
        if (!arrayp(value) || sizeof(value) != 2) {
            continue;
        }

        operation = value[0];
        set_value = value[1];

        // Build SQL based on operation
        switch(operation) {
            case "add":
                // Arithmetic operation
                if (intp(set_value)) {
                    updates += ({ sprintf("%s = %s + %d", field, field, set_value) });
                }
                else if (floatp(set_value)) {
                    updates += ({ sprintf("%s = %s + %f", field, field, set_value) });
                }
                break;

            case "set":
                // Direct assignment
                if (intp(set_value)) {
                    updates += ({ sprintf("%s = %d", field, set_value) });
                }
                else if (floatp(set_value)) {
                    updates += ({ sprintf("%s = %f", field, set_value) });
                }
                else if (stringp(set_value)) {
                    updates += ({ sprintf("%s = %s", field, DB_STR(set_value)) });
                }
                break;

            default:
                // Invalid operation
                continue;
        }
    }

    // No valid updates
    if (!sizeof(updates)) {
        return 0;
    }

    // Build and execute query
    sql = sprintf("UPDATE members SET %s WHERE id = %s",
                  implode(updates, ", "),
                  DB_STR(id));

    result = DATABASE_D->db_query(sql);

    // Return number of rows affected
    return (result > 0) ? result : 0;
}

// 設定會員屬性
public int db_set_member(mixed ob, string key, mixed data) {
    mixed ret;
    string id, sql;

    if (!valid_caller())
        return 0;

    if (objectp(ob))
        id = query("id", ob);
    else
        if (stringp(ob))
        id = ob;
    else
        return 0;

    if (!stringp(id)  || id  == "" ||
        !stringp(key) || key == "")
        return 0;

    if (intp(data))
        sql = "UPDATE members SET " + key + "=" + data + " WHERE id = " + DB_STR(id);
    else if (mapp(data) || arrayp(data))
        sql = "UPDATE members SET " + key + "=" + DB_STR(save_variable(data)) + " WHERE id = " + DB_STR(id);
    else if (stringp(data))

    sql = "UPDATE members SET " + key + "=" + DB_STR(data) + " WHERE id = " + DB_STR(id);

    else
        return 0;

    ret = DATABASE_D->db_query(sql);
    if (!intp(ret) || ret < 1)  // Should affect at least 1 row
        return 0;

    return 1;  // Return success, not row count
}

// 增加會員屬性點
public int db_add_member(mixed ob, string key, int num) {
    mixed ret;
    string id, sql;

    if (!valid_caller())
        return 0;

    if (objectp(ob))
        id = query("id", ob);
    else
        if (stringp(ob))
        id = ob;
    else
        return 0;

    if (!stringp(id)  || id  == "" ||
        !stringp(key) || key == "" ||
        !intp(num)    || !num)
    return 0;

    sql = sprintf("UPDATE %s SET %s = %s + %d WHERE id = %s",
        MEMBER_TABLE, key, key, num, DB_STR(id));

    ret = DATABASE_D->db_query(sql);
    if (!intp(ret) || ret < 1)  // Should affect at least 1 row
        return 0;

    return 1;  // Return success, not row count
}

// 會員卡
public varargs mixed db_fee_member(mixed ob, int day, int flag)
{
    mixed ret;
    string id, sql;
    int jointime, endtime;
    object user, obj;

    if (!valid_caller())
        return 0;

    if (objectp(ob))
    {
        id = query("id", ob);
        user = ob;
    }
    else
        if (stringp(ob))
    {
        id = ob;
        user = find_player(id);
    }
    else
        return 0;

    if (!user) return 0;
    BAN_D->add_welcome_user(id);

    ret = db_query_member(id, ({"jointime", "endtime"}));

    jointime = to_int(ret["jointime"]);
    if (jointime < 1)
    {
        jointime = time();
        if (day > 90) addn("balance", 30000000, user);
        else addn("balance", 10000000, user);
    }

    if (flag)
    {
        day = 1999999999;
        obj = new("/d/room/obj/ultracard");
        obj->move(user, 1);
        obj = new("/clone/goods/noname");
        obj->move(user, 1);
    }
    else
    {
        endtime = to_int(ret["endtime"]);
        if (endtime < 1 || endtime < time())
            day = time() + day * 86400;
        else
            day = endtime + day * 86400;
    }

    sql = sprintf("UPDATE %s SET jointime = %d, endtime = %d WHERE id = %s",
        MEMBER_TABLE, jointime, day, DB_STR(id));

    ret = DATABASE_D->db_query(sql);
    if (!intp(ret) || ret < 1)  // Should affect at least 1 row
        return 0;

    return 1;  // Return success, not row count
}

// 會員衝值
public varargs int db_pay_member(mixed ob, int money, string from_id)
{
    string id, sql;
    string payinfo;
    string info;
    int paytimes, payvalue, last_payvalue;
    mixed ret;
    object target;

    if (!valid_caller())
        return 0;

    if (objectp(ob))
        id = query("id", ob);
    else
        if (stringp(ob))
        id = ob;
    else
        return 0;

    if (!stringp(id) || id == "")
        return 0;

    /*
     * if (!is_member(id))
     * {
     * db_create_member(id, money, from_id);
     * return 1;
     * }
     */
    ret = db_query_member(id, ({"paytimes", "payinfo", "payvalue", "money"}));
    paytimes = to_int(ret["paytimes"]) + 1;
    payinfo = ret["payinfo"];
    if (!payinfo) payinfo = "";

    if (!stringp(from_id) || from_id == "")
        info = sprintf("你於 %s 衝值 %d $NT。\n", TIME_D->replace_ctime(time()), money);
    else
        info = sprintf("你於 %s 收到 %s 的轉帳 %d $NT。\n",
            TIME_D->replace_ctime(time()), from_id, money);

    payinfo += info;
    payvalue = to_int(ret["payvalue"]) + money;
    last_payvalue = money;
    money += to_int(ret["money"]);
    /*
     * sql = sprintf("UPDATE %s SET money = %d, paytimes = %d, payinfo = \"%s\",
     * payvalue = %d, last_payvalue = %d, last_paytime = %d WHERE id = %s",
     * MEMBER_TABLE, money, paytimes, payinfo, payvalue, last_payvalue, time(), DB_STR(id));
     */
    sql = "UPDATE members SET money=" + money + ", paytimes=" + paytimes + ", payinfo=" + DB_STR(payinfo) +
        ", payvalue=" + payvalue + ", last_payvalue=" + last_payvalue + ", last_paytime=" +time() + " WHERE id= " + DB_STR(id);

    ret = DATABASE_D->db_query(sql);

    if (!intp(ret) || ret < 1)  // Should affect at least 1 row
        return 0;

    if (objectp(target = find_player(id)))
    {
        tell_object(target, "\a", 0);
        tell_object(target, HIR + info + NOR);
    }

    return 1;
}

public varargs int player_pay(mixed from, int money, mixed to)
{
    mixed ret;
    string fid, sql;

    if (!from)
        return 0;

    if (objectp(from))
        fid = query("id", from);
    else if (stringp(from))
        fid = from;
    else
        return 0;

    if (!stringp(fid) || fid == "" || !money)
        return 0;

    // Only update if user has enough money
    sql = sprintf("UPDATE %s SET money = money - %d WHERE id = %s AND money >= %d",
        MEMBER_TABLE, money, DB_STR(fid), money);

    ret = DATABASE_D->db_query(sql);

    // Check if query succeeded and affected exactly 1 row
    if (!intp(ret) || ret != 1)
        return 0;

    if (to)
    {
        money = money*99 / 100;
        if (money < 1) money = 1;
        if (MEMBER_D->is_member(to))
            MEMBER_D->db_pay_member(to, money, fid);
        else
            MEMBER_D->db_create_member(to, money, fid);
    }
    return 1;
}

// 會員轉帳
public int db_transfer_member(mixed ob, mixed to, int value) {
    string id, to_id;
    string zhuaninfo;
    string sql;
    object target;
    mixed ret;

    if (!valid_caller())
        return 0;

    if (objectp(ob))
        id = query("id", ob);
    else
        if (stringp(ob))
        id = ob;
    else
        return 0;

    if (objectp(to))
        to_id = query("id", to);
    else
        if (stringp(to))
        to_id = to;
    else
        return 0;

    if (!stringp(id) || id == "" ||
        !stringp(to_id) || to_id == "" ||
        !intp(value) || value < 1)
    return 0;

    target = UPDATE_D->global_find_player(to_id);
    if (!objectp(target))
    {
        write("沒有這個玩家，請檢查確認後再試！\n");
        return 0;
    }

    UPDATE_D->global_destruct_player(target, 1);

    if (!is_member(id))
    {
        write("您目前沒有充值記錄，也沒有王者金幣！\n");
        return 0;
    }

    // Use atomic UPDATE with WHERE clause to prevent race condition
    sql = sprintf("UPDATE %s SET money = money - %d WHERE id = %s AND money >= %d", MEMBER_TABLE, value, DB_STR(id), value);

    ret = DATABASE_D->db_query(sql);
    if (!intp(ret) || ret != 1)
    {
        write("轉帳失敗，餘額不足或數據庫錯誤！\n");
        return 0;
    }

    if (!is_member(to_id))
        db_create_member(to_id, value, id);
    else
        db_pay_member(to_id, value, id);

    ret = db_query_member(id, ({"transferinfo"}));
    zhuaninfo = ret["transferinfo"];

    if(!zhuaninfo)zhuaninfo = "";

    zhuaninfo += sprintf("你於 %s 轉帳 %d $NT給玩家 %s。\n",
        TIME_D->replace_ctime(time()),
        value,
        to_id);

    db_bulk_update_member(ob, ([
        "transferinfo": ({ "set", zhuaninfo }),
        "transfervalue": ({ "add", value }),
        "transfertimes": ({ "add", 1 }),
    ]));
    write(HIG "轉帳成功， 您的轉帳記錄已寫入文件，請使用 " HIR "member show zhuaninfo " HIG " 查詢！ \n" NOR);
    write(HIC "您總共轉帳了 " + HIY + value + HIC + " $NT , 祝您好運！\n" NOR);

    return 1;
}

public void show_member_info(mixed ob, string arg) {
    mixed ret;
    string id;
    int money, jointime, endtime, payvalue;
    int paytimes, buyvalue, buytimes, transfervalue;
    int transfertimes, last_paytime, last_buytime, last_buyvalue;
    string last_buyob;

    if (objectp(ob))
        id = query("id", ob);
    else
        if (stringp(ob))
        id = ob;
    else
        return 0;

    switch(arg)
    {
        // 充值記錄
    case "payinfo":
        if (!is_member(ob))
        {
            write("您目前沒有充值記錄！\n");
            return;
        }
        ret = db_query_member(ob, arg);
        if (!stringp(ret[0]) || ret[0] == "")
        {
            write("您目前沒有充值記錄！\n");
            return;
        }
        ob->start_more(BBLU + HIW "您的充值記錄如下：\n\n" NOR + BBLU + HIY + ret[0] + "\n" NOR);
        break;

        // 購買記錄
    case "buyinfo":
        if (!is_member(ob))
        {
            write("您目前沒有購買記錄！\n");
            return;
        }
        ret = db_query_member(ob, arg);
        if (!stringp(ret[0]) || ret[0] == "")
        {
            write("您目前沒有購買記錄！\n");
            return;
        }
        ob->start_more(BBLU + HIW "您的購買記錄如下：\n\n" NOR + BBLU + HIY + ret[0] + "\n" NOR);
        break;

        // 轉帳記錄
    case "zhuaninfo":
    case "transferinfo":
        if (!is_member(ob))
        {
            write("您目前沒有轉帳記錄！\n");
            return;
        }
        ret = db_query_member(ob, arg);
        if (!stringp(ret[0]) || ret[0] == "")
        {
            write("您目前沒有轉帳記錄！\n");
            return;
        }
        ob->start_more(BBLU + HIW "您的轉帳記錄如下：\n\n" NOR + BBLU + HIY + ret[0] + "\n" NOR);

        // 面板
    case "info":
        ret = db_query_member(ob, ({"money", "jointime", "endtime", "payvalue", "paytimes", "buyvalue", "buytimes",
                                  "transfervalue", "transfertimes", "last_paytime", "last_buytime", "last_buyob",
                                  "last_buyvalue"}));
        money = to_int(ret["money"]);
        jointime = to_int(ret["jointime"]);
        endtime = to_int(ret["endtime"]);
        payvalue = to_int(ret["payvalue"]);
        paytimes = to_int(ret["paytimes"]);
        buyvalue = to_int(ret["buyvalue"]);
        buytimes = to_int(ret["buytimes"]);
        transfervalue = to_int(ret["transfervalue"]);
        transfertimes = to_int(ret["transfertimes"]);
        last_paytime = to_int(ret["last_paytime"]);
        last_buytime = to_int(ret["last_buytime"]);
        last_buyob = ret["last_buyob"];
        last_buyvalue = to_int(ret["last_buyvalue"]);

        write(BBLU + HIW "\t\t       "+LOCAL_MUD_NAME() + "會員系統面板\t\t     " + VERSION + "\n" NOR);
        write(HIW "≡---------------------------------------------------------------≡\n" NOR);
        write(HIY "WELCOME TO JOIN IN THE MEMBERS OF NT AND HOPE YOU ALL GOES WELL.\n\n" NOR);

        write(sprintf(HIC "  會員代號：%-25s金幣餘額：%s\n" NOR,
        id, to_string(money) + " $NT"));
        write(sprintf(HIC "  入會時間：%-25s有效時間：%s\n" NOR,
        jointime > 0 ?
        TIME_D->replace_ctime(jointime) : "沒有入會",
            endtime > 1888888888 ?
            "終身會員" : (endtime ?
            TIME_D->replace_ctime(endtime) : "0")));
        write(sprintf(HIC "  衝值累計：%-25s充值次數：%d\n" NOR,
            to_string(payvalue) + " $NT",
            paytimes));
        write(sprintf(HIC "  購買累計：%-25s購買次數：%d\n" NOR,
            to_string(buyvalue) + " $NT",
            buytimes));
        write(sprintf(HIC "  轉帳累計：%-25s轉帳次數：%d\n" NOR,
            to_string(transfervalue) + " $NT",
            transfertimes));
        write(sprintf(HIM "\n  您最後一次充值時間是               %s\n" NOR,
            TIME_D->replace_ctime(last_paytime)));
        write(sprintf(HIM "  您最後一次購買時間是               %s\n" NOR,
            last_buytime ?
            TIME_D->replace_ctime(last_buytime) : "————"));
        write(sprintf(HIM "  您最後一次購買物品是               %s(%s)\n" NOR,
            sizeof(last_buyob) ?
            last_buyob : "————",
            last_buyvalue ?
            to_string(last_buyvalue) + " $NT" : "0"));

        write(HIG "\n  *請使用" HIR " member show info " HIG "          打開泥潭會員系統面板。\n" NOR);
        write(HIG "  *請使用" HIR " member show payinfo " HIG "       查看歷史充值記錄。\n" NOR);
        write(HIG "  *請使用" HIR " member show buyinfo " HIG "       查看購買物品記錄。\n" NOR);
        write(HIG "  *請使用" HIR " member show zhuaninfo " HIG "     查看歷史轉帳記錄。\n" NOR);
        write(HIG "  *請使用" HIR " member show goods " HIG "         查看王者商店出售的物品。\n" NOR);
        write(HIG "  *請使用" HIR " member zhuan <$NT> to <id>" HIG " 轉帳金幣($NT)給別的角色(ID)。\n" NOR);
        write(HIG "  *請使用" HIR " member buy <物品代號> " HIG "     購買物品。\n" NOR);
        write(HIG "  *請使用" HIR " member look <物品代號> " HIG "    查看物品。\n" NOR);
        write(HIG "  *請使用" HIR " member check <id> " HIG "         檢查會員信息。\n" NOR);
        write(HIG "  *請使用" HIR " member stats " HIG "              列出所有的會員。\n" NOR);
        write(HIG "  *請使用" HIR " member ?? " HIG "                 member 指令幫助。\n\n\n" NOR);


        write(HIR "  為避免帶來不必要的損失請認真閱讀"+LOCAL_MUD_NAME() + "會員制度文件" HIY "(help member)\n\n" NOR);
        write(HIY "                                                 NT WIZARD GROUP\n" NOR);
        write(HIW "≡---------------------------------------------------------------≡\n" NOR);

        break;
        // 物品清單
    case "goods":
        GOODS_D->show_goods(ob);
        break;

    default:
        break;
    }

    return;
}

public mixed show_all_members(int flag) {
    int nCount, m = 0;
    string status;
    object ob;
    string name, jointime;
    mixed members;

    members = DATABASE_D->db_all_query(sprintf("SELECT id, jointime FROM %s WHERE endtime >= %d", MEMBER_TABLE, time()));


    if (!sizeof(members))
    {
        if (flag) return ({});
        write(HIG "暫無會員！\n" NOR);
        return;
    }

    if (flag) return members;

    write(HIM "以下是"+LOCAL_MUD_NAME() + "的所有會員列表：\n" NOR);
    write(HIW "≡-------------------------------------------------------------------≡\n" NOR);

    write(sprintf(HIR "%-18s%-18s%-26s%-20s\n\n" NOR,
        "姓  名", "帳  號", "入會時間", "狀  況"));

    for (nCount = 0; nCount < sizeof(members); nCount ++)
    {
        if (ob = find_player(members[nCount][0]))
        {
            if(query("doing", ob))status = HIY"計劃中"NOR;
            else if (interactive(ob) && query_idle(ob) > 120)status = HIM "發呆" NOR;
            else if (is_valid_member(members[nCount][0]))status = HIW "在線" NOR;
            else status = HIR "過期" NOR;
            name = ob->name(1);
            jointime = TIME_D->replace_ctime(to_int(members[nCount][1]));
        }
        else
        {
            if (is_valid_member(members[nCount][0])) status = NOR + WHT "離線" NOR;
            else status = HIR "過期" NOR;
            name = "———";
            jointime = "———";
        }

        write(sprintf(HIG "%-18s%-18s%-26s%-20s\n" NOR,
            name,
            members[nCount][0],
            jointime,
            status));

        m ++;   // 過濾掉轉帳記錄文件，實際會員數

    }
    write(HIY "\n總共有 " + m + " 名註冊會員。\n" NOR);
    write(HIW "≡-------------------------------------------------------------------≡\n\n" NOR);
    return 1;
}

#endif
