from django.db import models
from django.contrib.auth.models import User

def upload_name(instance,file):
    return '/'.join([instance.user,file])

class Upload(models.Model):
    user = models.CharField(max_length=50,null=True)
    files = models.FileField(upload_to=upload_name, blank=True, null=True)
    # files = models.FileField(widget=models.ClearableFileInput(attrs={'multiple': True}),upload_to=upload_name, blank=True, null=True)

