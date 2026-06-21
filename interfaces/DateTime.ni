module DateTime;

@nodispose
opaque Handle {
    string toISO8601();
}

opaque Owned extends Handle;

Owned createFromISO8601(string text);
