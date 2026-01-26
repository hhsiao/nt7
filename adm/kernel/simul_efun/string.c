// Helper function for formatting table rows with auto-sizing and word wrapping
string format_table_row(string *columns, int *widths, string *aligns, string *colors) {
    string result, col, align, color;
    int i, len, padding, width, padding_left, padding_right;

    result = "";

    for(i = 0; i < sizeof(columns); i++) {
        col = columns[i];
        width = widths[i];
        align = aligns[i];
        color = colors[i];

        // Add space separator between columns (but not before first column)
        if(i > 0) result += " ";

        // Calculate display length (excluding color codes)
        len = strwidth(col);

        if(align == "right") {
            padding = width - len;
            result += color + sprintf("%*s%s", padding, "", col) + NOR;
        } else if(align == "center") {
            padding_left = (width - len) / 2;
            padding_right = width - len - padding_left;
            result += color + sprintf("%*s%s%*s", padding_left, "", col, padding_right, "") + NOR;
        } else { // left align (default)
            padding = width - len;
            result += color + col + sprintf("%*s", padding, "") + NOR;
        }
    }

    return result + "\n";
}

// Word wrap text to fit within specified width
string *word_wrap(string text, int width) {
    string *lines, *tokens, current_line, token;
    int line_len, token_len, i, j;

    lines = ({});
    current_line = "";
    tokens = ({});

    if(strwidth(text) <= width) {
        return ({ text });
    }

    // Split into tokens: separate words by spaces, but keep Chinese characters together
    i = 0;
    while(i < strlen(text)) {
        if(text[i..i] == " ") {
            tokens += ({ " " });
            i++;
        } else if(text[i] < 0 || text[i] >= 128) {
            // Multi-byte character (Chinese), add as single token
            // Find the full multi-byte sequence
            j = i;
            while(j < strlen(text) && (text[j] < 0 || text[j] >= 128)) {
                j++;
                // UTF-8: continuation bytes start with 10xxxxxx (128-191)
                while(j < strlen(text) && text[j] >= 128 && text[j] < 192) {
                    j++;
                }
                // Only take one character at a time for wrapping flexibility
                break;
            }
            tokens += ({ text[i..j-1] });
            i = j;
        } else {
            // ASCII character (English word), collect the whole word
            j = i;
            while(j < strlen(text) && text[j] >= 0 && text[j] < 128 && text[j..j] != " ") {
                j++;
            }
            tokens += ({ text[i..j-1] });
            i = j;
        }
    }

    // Now build lines from tokens
    foreach(token in tokens) {
        if(token == " ") {
            if(current_line != "") {
                current_line += " ";
            }
            continue;
        }

        token_len = strwidth(token);
        line_len = strwidth(current_line);

        if(current_line == "") {
            if(token_len <= width) {
                current_line = token;
            } else {
                // Token too long, have to break it (shouldn't happen with single chars/words)
                lines += ({ token });
            }
        } else if(line_len + token_len <= width) {
            current_line += token;
        } else {
            // Start new line
            lines += ({ current_line });
            current_line = token;
        }
    }

    if(current_line != "") {
        lines += ({ current_line });
    }

    return lines;
}

// Main table formatting function
string format_table(mapping *data, mapping *column_specs) {
    string msg, separator, *headers, *h_colors, *h_aligns, *values, *colors, *aligns, *line_values, value;
    int i, j, *widths, max_width, val_len, max_lines;
    mixed *wrapped_values;
    mapping row;

    msg = "";
    widths = allocate(sizeof(column_specs));

    // Calculate column widths
    for(i = 0; i < sizeof(column_specs); i++) {
        if(column_specs[i]["fixed_width"]) {
            // Use fixed width if specified
            widths[i] = column_specs[i]["fixed_width"];
        } else {
            // Auto-calculate width based on header and data
            max_width = strwidth(column_specs[i]["header"]);

            foreach(row in data) {
                value = row[column_specs[i]["key"]];
                val_len = strwidth(value);
                if(val_len > max_width) max_width = val_len;
            }

            widths[i] = max_width;
        }
    }

    // Build header
    headers = allocate(sizeof(column_specs));
    h_colors = allocate(sizeof(column_specs));
    h_aligns = allocate(sizeof(column_specs));

    for(i = 0; i < sizeof(column_specs); i++) {
        headers[i] = column_specs[i]["header"];
        h_colors[i] = column_specs[i]["header_color"] || HIW;
        h_aligns[i] = column_specs[i]["align"] || "left";
    }

    msg += format_table_row(headers, widths, h_aligns, h_colors);

    // Add separator - calculate total width including spaces
    separator = "";
    for(i = 0; i < sizeof(widths); i++) {
        if(i > 0) separator += "-";  // Dash for the space between columns
        separator += repeat_string("-", widths[i]);
    }
    msg += HIG + separator + "\n\n" + NOR;

    // Build data rows
    foreach(row in data) {
        values = allocate(sizeof(column_specs));
        colors = allocate(sizeof(column_specs));
        aligns = allocate(sizeof(column_specs));
        wrapped_values = allocate(sizeof(column_specs));
        max_lines = 1;

        // Prepare values and handle word wrapping
        for(i = 0; i < sizeof(column_specs); i++) {
            values[i] = row[column_specs[i]["key"]];
            colors[i] = column_specs[i]["color"] || NOR;
            aligns[i] = column_specs[i]["align"] || "left";

            if(column_specs[i]["fixed_width"]) {
                wrapped_values[i] = word_wrap(values[i], widths[i]);
                if(sizeof(wrapped_values[i]) > max_lines) {
                    max_lines = sizeof(wrapped_values[i]);
                }
            } else {
                wrapped_values[i] = ({ values[i] });
            }
        }

        // Output multi-line row
        for(j = 0; j < max_lines; j++) {
            line_values = allocate(sizeof(column_specs));

            for(i = 0; i < sizeof(column_specs); i++) {
                if(j < sizeof(wrapped_values[i])) {
                    line_values[i] = wrapped_values[i][j];
                } else {
                    line_values[i] = "";
                }
            }

            msg += format_table_row(line_values, widths, aligns, colors);
        }
    }

    return msg;
}
