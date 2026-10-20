module Date;

@nodispose
opaque Handle {
    string toISO8601();
}
@useparenttype
opaque Owned extends Handle;

Owned createFromISO8601(string text);
