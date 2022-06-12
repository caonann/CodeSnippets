class model:
    create_at='abc'
    @property
    def create_at(self):
        return self.create_at+"aaa"

m = model()
#print(m.create_at)

a="1"
print(int(a))